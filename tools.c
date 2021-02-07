#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "tools.h"
void teachers_list(course * head, char* std_username)
{
	int counter = 0;
	course * temp = head;
	printf("-----------------------------------------------------------\n");
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (temp->status == 1 && strcmp(temp->std_username, std_username) == 0)
		{
			printf("%s\n", temp->tch_username);
			counter++;
		}
	}
	if (counter == 0)
		printf("YOU HAVE NO COURSE WITH ANY TEACHERS\n");
	printf("-----------------------------------------------------------\n");
}
void show_grades(course * head, char * username)
{/*shows all the grades given to the student and shows their average*/
	int counter1 = 0;
	float * grades;
	float sum = 0.0;
	grades = (float *)malloc(sizeof(float));
	course * temp = head;
	printf("-----------------------------------------------------------\n");
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (strcmp(temp->std_username, username) == 0)
		{
			if (strcmp(temp->grade, "-1") == 0)
				continue;
			else
			{
				grades[counter1] = atof(temp->grade);
				sum += grades[counter1];
				grades = (float *)realloc(grades, (counter1 + 2) * sizeof(float));
				printf("TEACHER : %s  GRADE : %.2f \n", temp->tch_username, grades[counter1]);
				counter1++;
			}
		}
	}
	if (sum == 0.0)
		printf("YOU DON'T HAVE ANY GRADE\n");
	else
		printf("AVERAGE : %.2f \n", (sum / counter1));
	printf("-----------------------------------------------------------\n");
}
//
//
//
void show_grade(course * head, char * tch_username, char * std_username)
{/*shows the grade of an specific teacher*/
	course * temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (strcmp(temp->tch_username, tch_username) == 0 && strcmp(temp->std_username, std_username) == 0 && temp->status == 1)
		{
			if (strcmp(temp->grade, "-1") == 0)
			{
				printf("YOU ARE NOT GRADED YET\n");
				return;
			}
			else
			{
				printf("YOUR GRADE IS : %s\n", temp->grade);
				return;
			}
		}
	}
	printf("YOU DON'T HAVE A COURSE WITH THIS TEACHER\n");
	return;
}
//
//
//
void grade_std(course * head, char * tch_username, char * std_username, char * grade)
{/*lets the teacher grade a student*/
	course * temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (strcmp(temp->tch_username, tch_username) == 0 && strcmp(temp->std_username, std_username) == 0 && temp->status == 1)
		{
			temp->grade = strdup(grade);
			printf("STUDENT \"%s\" GRADED \n", temp->std_username);
			return;
		}
		else if (strcmp(temp->tch_username, tch_username) == 0 && strcmp(temp->std_username, std_username) == 0 && temp->status == 0)
		{
			printf("YOU HAVE TO ACCEPT STUDENT \"%s\" FIRST\n", temp->std_username);
			return;
		}
	}
	printf("YOU DON'T HAVE ANY COURSE WITH THIS STUDENT\n");
	return;
}
//
//
//
void accept(course * head, char * tch_username, char * std_username)
{/*accepts a student requested to have a course with the teacher*/
	course * temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (strcmp(temp->tch_username, tch_username) == 0 && strcmp(temp->std_username, std_username) == 0 && temp->status == 0)
		{
			temp->status = 1;
			printf("STUDENT \"%s\" ACCEPTED\n", temp->std_username);
			return;
		}
		else if (strcmp(temp->tch_username, tch_username) == 0 && strcmp(temp->std_username, std_username) == 0 && temp->status == 1)
		{
			printf("YOU HAVE ALREADY ACCEPTED THIS STUDENT\n");
			return;
		}
	}
	printf("STUDENT DOESN'T HAVE ANY COURSE WITH YOU\n");
	return;
}
//
//
//
void read_from_files(FILE * STDf, FILE * TCHf, FILE * CRSf, student * temp1, teacher * temp2, course * temp3)
{/*reads from the files and saves*/
	char *token1 = (char *)malloc(sizeof(char));
	char *token2 = (char *)malloc(sizeof(char));
	char *token3 = (char *)malloc(sizeof(char));
	int status;
	while (!feof(STDf))
	{
		while (temp1->next != NULL)
		{
			temp1 = temp1->next;
		}
		temp1->next = (student *)malloc(sizeof(student));
		temp1 = temp1->next;
		fscanf(STDf, "%s %s", token1, token2);
		temp1->username = strdup(token1);
		temp1->password = strdup(token2);
		temp1->next = NULL;
	}
	while (!feof(TCHf))
	{
		while (temp2->next != NULL)
		{
			temp2 = temp2->next;
		}
		temp2->next = (teacher *)malloc(sizeof(teacher));
		temp2 = temp2->next;
		fscanf(TCHf, "%s %s", token1, token2);
		temp2->username = strdup(token1);
		temp2->password = strdup(token2);
		temp2->next = NULL;
	}
	while (!feof(CRSf))
	{
		while (temp3->next != NULL)
		{
			temp3 = temp3->next;
		}
		temp3->next = (course *)malloc(sizeof(course));
		temp3 = temp3->next;
		fscanf(CRSf, "%s %s %s %d", token1, token2, token3, &status);
		temp3->tch_username = strdup(token1);
		temp3->std_username = strdup(token2);
		temp3->grade = strdup(token3);
		temp3->status = status;
		temp3->next = NULL;
	}
}
//
//
//
char * ordeer(char * order, char * token)
{/*gets the order from the user*/
	char c;
	int counter1 = 1;
	while ((c = getchar()) != '\n')
	{
		order[counter1 - 1] = c;
		counter1++;
	}
	order[counter1 - 1] = NULL;
	token = strtok(order, " ");
	return token;
}
//
//
//
void requests_list(course * chead, char * username)
{/*shows the requests sent to teacher*/
	course * temp = chead;
	int counter = 0;
	printf("-----------------------------------------------------------\n");
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (strcmp(temp->tch_username, username) == 0 && temp->status == 0)
		{
			printf("%s\n", temp->std_username);
			counter++;
		}
	}
	if (counter == 0)
	{
		printf("YOU HAVE NO REQUESTS\n");
	}
	printf("-----------------------------------------------------------\n");
}
//
//
//
course * make_course(course * head, char * std_username, char * tch_username)
{
	course *temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (strcmp(temp->tch_username, tch_username) == 0 && strcmp(temp->std_username, std_username) == 0 && temp->status == 0)
		{
			printf("YOU HAVE ALREADY REQUESTED A COURSE WITH THIS TEACHER!!!\n");
			return NULL;
		}
	}
	temp->next = (course *)malloc(sizeof(course));
	temp = temp->next;
	temp->status = -1;
	temp->grade = strdup("-1");
	temp->next = NULL;
	return temp;
}
//
//
//
teacher * find_teacher(teacher * head, char * username)
{
	teacher * temp = head;
	while (head->next != NULL)
	{
		head = head->next;
		if (strcmp(head->username, username) == 0)
		{
			return head;
		}
	}
	return NULL;
}
//
//
//
void request_course(char* token2, char * username, teacher *head, course *head1, FILE *CRSf)
{
	teacher *thead = head;
	course *chead = head1;
	if (token2 == NULL)
	{
		printf("ENTER A TEACHER'S USERNAME!!!\n");
		return;
	}
	thead = find_teacher(head, token2);
	if (thead == NULL)
	{
		printf("TEACHER DOESN'T EXIST\n");
		return;
	}
	chead = make_course(head1, username, token2);
	if (chead == NULL)
	{
		printf("CAN'T MAKE THIS COURSE\n");
		return;
	}
	chead->std_username = strdup(username);
	chead->tch_username = strdup(token2);
	chead->status = 0;
	printf("REQUEST SENT TO \"%s\"\n", token2);
}
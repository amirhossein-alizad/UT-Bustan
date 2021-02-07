#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "tools.h"
#include "signups_and_logins.h"
student * signup_student(student* head, char*token2, char*token3, FILE *STDf)
{
	student * temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (strcmp(temp->username, token2) == 0)
		{
			printf("USERNAME TAKEN\n");
			return NULL;
		}
	}
	temp->next = (student *)malloc(sizeof(student));
	temp = temp->next;
	temp->username = strdup(token2);
	temp->password = strdup(token3);
	temp->next = NULL;
	fprintf(STDf, "%s %s\n", token2, token3);
	printf("USER \"%s\" ADDED AS STUDENT\n", token2);
	return temp;
}
//
//
//
teacher * signup_teacher(teacher * head, char*token2, char*token3, FILE *TCHf)
{
	teacher * temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (strcmp(temp->username, token2) == 0)
		{
			printf("USERNAME TAKEN\n");
			return NULL;
		}
	}
	temp->next = (teacher *)malloc(sizeof(teacher));
	temp = temp->next;
	temp->username = strdup(token2);
	temp->password = strdup(token3);
	temp->next = NULL;
	fprintf(TCHf, "%s %s \n", token2, token3);
	printf("USER \"%s\" ADDED AS TEACHER\n", token2);
	return temp;
}

//
//
//

void  login_student(char *order, student * head, teacher * head2, course * head3, char * username, char * password, FILE * CRSf, FILE * STDf, FILE * TCHf)
{
	student *temp;
	teacher *thead = head2;
	course *chead = head3;
	temp = head;
	char c;
	char *token1, *token2, *token3;
	token3 = (char *)malloc(sizeof(char));
	int counter1 = 1;
	int counter2 = 1;
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (strcmp(temp->username, username) == 0 && strcmp(temp->password, password) == 0)
		{
			printf("YOU LOGGED IN SUCCESSFULY AS \"%s\"\n", temp->username);
			while (1)
			{
				token1 = ordeer(order, token3);

				if (strcmp(token1, "logout") == 0)
				{
					printf("YOU LOGGED OUT SUCCESSFULY\n");
					return;
				}
				else if (strcmp(token1, "request_course") == 0)
				{
					token2 = strtok(NULL, " \n");
					token3 = strdup(temp->username);
					if (token2 == NULL)
					{
						printf("ENTER A TEACHER'S USERNAME\n");
						continue;
					}
					request_course(token2, token3, thead, chead, CRSf);
				}
				else if (strcmp(token1, "EXIT") == 0)
				{
					fclose(STDf);
					fclose(TCHf);
					fclose(CRSf);
					exit(EXIT_SUCCESS);
				}
				else if (strcmp(token1, "show_grade") == 0)
				{
					token2 = strtok(NULL, " \n");
					if (token2 == NULL)
					{
						printf("ENTER A TEACHER'S USERNAME\n");
						continue;
					}
					show_grade(chead, token2, temp->username);
				}
				else if (strcmp(token1, "show_grades") == 0)
				{
					show_grades(chead, temp->username);
				}
				else if (strcmp(token1, "teachers_list") == 0)
				{
					teachers_list(chead, temp->username);
				}
				else
				{
					printf("BAD INPUT,TRY AGAIN\n");
				}
			}
		}
	}
	printf("WRONG PASSWORD OR USERNAME OR THE USERNAME DOESN'T EXIST\n");
	return;
}
//
//
//
void login_teacher(teacher * head, course * chead, char * username, char * password, char*token1, char*token2, char*token3, char* order, FILE *CRSf, FILE * STDf, FILE * TCHf)
{
	teacher *temp;
	temp = head;
	course *temp1 = chead;
	char c;
	int counter1 = 1, counter2 = 1;
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (strcmp(temp->username, username) == 0 && strcmp(temp->password, password) == 0)
		{
			printf("YOU LOGGED IN SUCCESSFULY AS \"%s\"\n", temp->username);
			while (1)
			{

				token1 = ordeer(order, token3);
				if (strcmp(token1, "logout") == 0)
				{
					printf("YOU LOGGED OUT SUCCESSFULY\n");
					return;
				}
				else if (strcmp(token1, "requests_list") == 0)
				{
					requests_list(temp1, username);
				}
				else if (strcmp(token1, "accept") == 0)
				{
					token2 = strtok(NULL, " \n");
					if (token2 == NULL)
					{
						printf("ENTER A STUDENT'S USERNAME\n");
						continue;
					}
					accept(temp1, temp->username, token2);
				}
				else if (strcmp(token1, "grade") == 0)
				{
					token2 = strtok(NULL, " \n");
					token3 = strtok(NULL, " \n");
					if (token2 == NULL)
					{
						printf("ENTER A STUDENT'S USERNAME\n");
						continue;
					}
					if (token3 == NULL)
					{
						printf("ENTER A GRADE\n");
						continue;
					}
					grade_std(chead, temp->username, token2, token3);
				}
				else if (strcmp(token1, "EXIT") == 0)
				{
					fclose(STDf);
					fclose(TCHf);
					fclose(CRSf);
					exit(EXIT_SUCCESS);
				}
				else
				{
					printf("BAD INPUT,TRY AGAIN\n");
				}
			}
		}
	}
	printf("WRONG PASSWORD OR USERNAME OR THE USERNAME DOESN'T EXIST\n");
	return;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "signups_and_logins.h"
#include "getorder.h"
#include "tools.h"
void get_order(char * order, student *shead, teacher *thead, course *chead, FILE *STDf, FILE *TCHf, FILE *CRSf)
{
	student * studenthead = shead, *studenthead2;
	teacher * teacherhead = thead;
	course * coursehead = chead;
	char *token1, *token2, *token3;
	token3 = (char*)malloc(sizeof(char));
	char*token4;
	token4 = (char *)malloc(sizeof(char));
	token1 = ordeer(order, token3);
	char c;
	int counter1 = 1;
	if (strcmp(token1, "signup_student") == 0)
	{
		token2 = strtok(NULL, " \n");
		token3 = strtok(NULL, " \n");
		if (token3 == NULL)
		{
			printf("YOU NEED TO ENTER A PASSWORD\n");
			return;
		}
		studenthead = signup_student(shead, token2, token3, STDf);
		if (studenthead == NULL)
		{
			printf("CAN NOT ADD STUDENT\n");
			return;
		}
		token3 = strdup(token2);
		while (1)
		{
			token1 = ordeer(order, token3);
			if (strcmp(token1, "logout") == 0)
			{
				printf("YOU LOGGED OUT SUCCESSFULY\n");
				return;
			}
			else if (strcmp(token1, "EXIT") == 0)
			{
				fclose(STDf);
				fclose(TCHf);
				fclose(CRSf);
				exit(EXIT_SUCCESS);
			}
			else if (strcmp(token1, "request_course") == 0)
			{
				token2 = strtok(NULL, " \n");
				if (token2 == NULL)
				{
					printf("ENTER A TEACHER'S USERNAME\n");
					continue;
				}
				request_course(token2, token3, thead, chead, CRSf);
			}
			else if (strcmp(token1, "show_grade") == 0)
			{
				token2 = strtok(NULL, " \n");
				if (token2 == NULL)
				{
					printf("ENTER A TEACHER'S USERNAME\n");
					continue;
				}
				show_grade(chead, token2, token3);
			}
			else if (strcmp(token1, "show_grades") == 0)
			{
				show_grades(chead, token2);
			}
			else if (strcmp(token1, "teachers_list") == 0)
			{
				teachers_list(chead, token2);
			}
			else
			{
				printf("BAD INPUT,TRY AGAIN\n");
			}
		}
	}
	else if (strcmp(token1, "signup_teacher") == 0)
	{
		token2 = strtok(NULL, " \n");
		token3 = strtok(NULL, " \n");
		if (token3 == NULL)
		{
			printf("YOU NEED TO ENTER A PASSWORD\n");
			return;
		}
		teacherhead = signup_teacher(thead, token2, token3, TCHf);
		if (teacherhead == NULL)
		{
			printf("CAN NOT ADD TEACHER\n");
			return;
		}
		token3 = strdup(token2);
		while (1)
		{
			token1 = ordeer(order, token3);
			if (strcmp(token1, "logout") == 0)
			{
				printf("YOU LOGGED OUT SUCCESSFULY\n");
				return;
			}
			else if (strcmp(token1, "EXIT") == 0)
			{
				fclose(STDf);
				fclose(TCHf);
				fclose(CRSf);
				exit(EXIT_SUCCESS);
			}
			else if (strcmp(token1, "requests_list") == 0)
			{
				requests_list(chead, token2);
			}
			else if (strcmp(token1, "accept") == 0)
			{
				token2 = strtok(NULL, " \n");
				if (token2 == NULL)
				{
					printf("ENTER A STUDENT'S USERNAME\n");
					continue;
				}
				accept(chead, token3, token2);
			}
			else if (strcmp(token1, "grade") == 0)
			{
				token2 = strtok(NULL, " \n");
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
				token4 = strtok(NULL, " \n");
				grade_std(chead, token3, token2, token4);
			}
			else
			{
				printf("BAD INPUT,TRY AGAIN\n");
			}
		}
	}
	else if (strcmp(token1, "login_student") == 0)
	{
		token2 = strtok(NULL, " \n");
		token3 = strtok(NULL, " \n");
		if (token3 == NULL)
		{
			printf("ENTER THE PASSWORD TO LOGIN\n");
			return;
		}
		login_student(order, studenthead, teacherhead, coursehead, token2, token3, CRSf, STDf, TCHf);
	}
	else if (strcmp(token1, "login_teacher") == 0)
	{
		token2 = strtok(NULL, " \n");
		token3 = strtok(NULL, " \n");
		if (token3 == NULL)
		{
			printf("ENTER THE PASSWORD TO LOGIN\n");
			return;
		}
		login_teacher(teacherhead, coursehead, token2, token3, token1, token2, token3, order, CRSf, STDf, TCHf);
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
		return;
	}
}
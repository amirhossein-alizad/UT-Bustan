#include "structs.h"
#include "readfromfiles.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void readfromfiles(FILE * STDf, FILE * TCHf, FILE * CRSf, student * temp1, teacher * temp2, course * temp3)
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "getorder.h"
#include "readfromfiles.h"
int main()
{
	FILE *STDf = fopen("stdinfo.txt", "a+"), *TCHf = fopen("tchinfo.txt", "a+"), *CRSf = fopen("crsinfo.txt", "a+");
	teacher dummyteacher;
	student dummystudent, *temp1 = &dummystudent;
	course dummycourse;
	dummycourse.next = NULL;
	dummystudent.next = NULL;
	dummyteacher.next = NULL;
	teacher *temp2 = &dummyteacher;
	course *temp3;
	temp3 = &dummycourse;
	char *order = (char *)malloc(sizeof(char));
	char *order2 = (char *)malloc(sizeof(char));
	//
	readfromfiles(STDf, TCHf, CRSf, temp1, temp2, temp3);
	while (1)
	{
		STDf = fopen("stdinfo.txt", "a+");
		TCHf = fopen("tchinfo.txt", "a+");
		get_order(order, &dummystudent, &dummyteacher, &dummycourse, STDf, TCHf, CRSf);
		fclose(STDf);
		fclose(TCHf);
		fclose(CRSf);
		CRSf = fopen("crsinfo.txt", "w+");
		temp3 = &dummycourse;
		while (temp3->next != NULL)
		{
			temp3 = temp3->next;
			fprintf(CRSf, "%s %s %s %d\n", temp3->tch_username, temp3->std_username, temp3->grade, temp3->status);
		}
		fclose(CRSf);
	}
}
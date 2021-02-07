#include <stdio.h>
#include "structs.h"
student * signup_student(student * head, char*token2, char*token3, FILE *STDf);
teacher * signup_teacher(teacher * head, char*token2, char*token3, FILE *TCHf);
void  login_student(char* order, student * head, teacher * head2, course * head3, char * username, char * password, FILE *, FILE *, FILE *);
void login_teacher(teacher * head, course * head2, char * username, char * password, char*token1, char*token2, char*token3, char*order, FILE *, FILE *, FILE *);
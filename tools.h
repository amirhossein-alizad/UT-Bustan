#include <stdio.h>
#include "structs.h"
teacher * find_teacher(teacher *, char *);
course * make_course(course *, char *, char *);
void request_course(char *, char*, teacher *, course *, FILE *);
void requests_list(course*, char*);
char * ordeer(char * order, char * token);
void accept(course * head, char * tch_username, char * std_username);
void grade_std(course * head, char * tch_username, char * std_username, char *);
void show_grade(course * head, char * tch_username, char * std_username);
void show_grades(course * head, char * username);
void teachers_list(course *, char* std_username);
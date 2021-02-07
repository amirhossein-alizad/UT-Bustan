#ifndef STRUCTS
#define STRUCTS
typedef struct students student;
typedef struct courses course;
typedef struct teachers teacher;
struct students {
	char * username;
	char * password;
	struct students * next;
};
struct teachers {
	char * username;
	char * password;
	struct teachers * next;
};
struct courses {
	char * tch_username;
	char * std_username;
	int status;
	char * grade;
	struct courses * next;
};
#endif // !STRUCTS

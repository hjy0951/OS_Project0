#include "utils.h"
#include <stdio.h>
#include <string.h>

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
	char* argvTemp = strtok(command, " \n\t"); // separate command std: \n\t
	*argv = (char**)malloc(sizeof(char*)*10); //allocate argv's row's memory

	if(argvTemp != NULL && strcmp(argvTemp, "alias") == 0) { // Not Null and enter "alias"
		*argc = 0; //initialize argc
		(*argv)[*argc] = (char*)malloc(sizeof(char)); // allocate argv's col's memory
		strcpy((*argv)[*argc], argvTemp); // copy first separated string
		(*argc)++; // because of the variable entered to argv
		if(argvTemp = strtok(NULL,"\n"))
		{
			//argvTemp = strtok(NULL,"\n"); // separate the rest of argvTemp

			(*argv)[*argc] = (char*)malloc(sizeof(char)); // allocate argv's col's memory
			strcpy((*argv)[*argc], argvTemp); // copy first separated string

			(*argc)++;
		}
	} else {
		for(*argc = 0; argvTemp != NULL ; (*argc)++) {
			(*argv)[*argc] = (char*)malloc(sizeof(char));
			strcpy((*argv)[*argc], argvTemp);
			argvTemp = strtok(NULL," \n\t");
		}
	}

	if(*argc == 0){ // if user enter only enter key
		(*argv)[*argc] = (char*)malloc(sizeof(char)); // allocate memory
		strcpy((*argv)[*argc], ""); // whitespace is entered => argv
		(*argc)++;
	}

	printf("argc : %d\n", *argc);
	for(int i = 0; i < *argc; i++) 
		printf("argv[%d] : %s\n", i, (*argv)[i]);
}

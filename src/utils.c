#include "utils.h"
#include <stdio.h>
#include <string.h>

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
	char* argvTemp = strtok(command, " \n\t");
	*argv = (char**)malloc(sizeof(char*)*10);

	for(*argc = 0; argvTemp != NULL ; (*argc)++) {
		(*argv)[*argc] = (char*)malloc(sizeof(char));
		strcpy((*argv)[*argc], argvTemp);
		argvTemp = strtok(NULL," \n\t");
	}

	if(*argc == 0){
		(*argv)[*argc] = (char*)malloc(sizeof(char));
		strcpy((*argv)[*argc], "");
		(*argc)++;
	}

	printf("argc : %d\n", *argc);
	for(int i = 0; i < *argc; i++) 
		printf("argv[%d] : %s\n", i, (*argv)[i]);
}

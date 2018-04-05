#include <string.h>
#include <unistd.h>

#include "commands.h"


int do_cd(int argc, char** argv) {
  if (!validate_cd_argv(argc, argv))
    return -1;
  int res = chdir(argv[1]);

  return res;
}

int do_pwd(int argc, char** argv) {
  if (!validate_pwd_argv(argc, argv))
    return -1;

  char buf[255];
  getcwd(buf, 255);
  printf("%s\n", buf);

  return 0;
}


int validate_cd_argv(int argc, char** argv) {
  // TODO: Fill it!
  if(argc == 1) return 0; // enter only cd -> error

  if(argc > 2){ // enter many arguement
    for(int i = 2 ; i <= argc ; i++)
      {
        (*argv)[i] = NULL; 
        // printf("\n%s\n",(*argv)[i]);
      }
  }
  return 1;
}

int validate_pwd_argv(int argc, char** argv) {
  // TODO: Fill it!
  
  //pwd has no argument!
  return 1;
}


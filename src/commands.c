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
  if(argc == 1 || argc > 2) return 0; 
  // enter only cd or many arguments -> error

  return 1;
}

int validate_pwd_argv(int argc, char** argv) {
  // TODO: Fill it!
  if(argc > 1) return 0; //enter many arguments(except pwd)
  return 1;
}


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

int do_alias(int argc, char** argv) {
  if (!validate_alias_argv(argc, argv))
    return -1;

  // TODO: Fill it!

  return 0;
}

int validate_cd_argv(int argc, char** argv) {
  // TODO: Fill it!
  return 1;
}

int validate_pwd_argv(int argc, char** argv) {
  // TODO: Fill it!
  return 1;
}

int validate_alias_argv(int argc, char** argv) {
  // TODO: Fill it!
  return 1;
}

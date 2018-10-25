#include <string.h>
#include <stdio.h>
// #include <unistd.h> // link, symlink, syscall
// #include <sys/stat.h> // mkdir
// #include <fcntl.h> // open
// #include <sys/syscall.h> // syscall macros
// #include <errno.h>

#define NUM_FD_ARGS 2
#define NUM_HS_ARGS 3

void createFile(char *newFile);
void createDir(char *newDir);
void createLink(char *oldFile, char *newFile);
void createSymLink(char *oldFile, char *newFile);

void create(int argc, char *argv[]) {
  if (argc == (NUM_FD_ARGS + 1)) {
    if (strcmp(argv[1], "-f") == 0) {
      // create file
      createFile(argv[2]);
    }
    else if (strcmp(argv[1], "-d") == 0) {
      // create directory
      createDir(argv[2]);
    }
    else {
      printf("invalid command.\n");
    }
  }
  else if (argc == (NUM_HS_ARGS + 1)) {
    if (strcmp(argv[1], "-h") == 0) {
      // create hard link
      link(argv[2], argv[3]);
    }
    else if (strcmp(argv[1], "-s") == 0) {
      // create soft link
      symlink(argv[2], argv[3]);
    }
    else {
      printf("invalid command.\n");
    }
  }
  else {
    printf("invalid number of arguments.\n");
  }
}

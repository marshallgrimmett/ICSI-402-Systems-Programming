#include <string.h>
#include <stdio.h>
// #include <fcntl.h>
// #include <sys/stat.h>

#define NUM_FD_ARGS 3
#define NUM_HS_ARGS 4

int createFile(char *newFile);
int createDir(char *newDir);
int createLink(char *oldFile, char *newFile);
int createSymLink(char *oldFile, char *newFile);

int main(int argc, char *argv[]) {
  int fd;
  if (argc == NUM_FD_ARGS) {
    if (strcmp(argv[1], "-f") == 0) {
      // create file
      fd = createFile(argv[2]);
      close(fd);
    }
    else if (strcmp(argv[1], "-d") == 0) {
      // create directory
      fd = createDir(argv[2]);
      close(fd);
    }
    else {
      printf("invalid command.\n");
    }
  }
  else if (argc == NUM_HS_ARGS) {
    if (strcmp(argv[1], "-h") == 0) {
      // create hard link
      fd = createLink(argv[2], argv[3]);
      close(fd);
    }
    else if (strcmp(argv[1], "-s") == 0) {
      // create soft link
      fd = createSymLink(argv[2], argv[3]);
      close(fd);
    }
    else {
      printf("invalid command.\n");
    }
  }
  else {
    printf("invalid number of arguments.\n");
  }
  return 0;
}

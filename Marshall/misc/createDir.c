#include <stdio.h>
#include <sys/stat.h> // mkdir
#include <errno.h>

void createDir(char *dirName) {
  int fd;
  if ((fd = mkdir(dirName, 0750)) != -1) {
    close(fd);
  }
  else {
    printf("error creating directory. error: %d\n", errno);
  }
}
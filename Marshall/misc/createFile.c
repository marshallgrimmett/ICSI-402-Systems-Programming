#include <stdio.h>
#include <fcntl.h> // open
#include <errno.h>

void createFile(char *fileName) {
  int fd;
  if ((fd = open(fileName, O_WRONLY | O_CREAT | O_TRUNC, 0640)) != -1) {
    close(fd);
  }
  else {
    printf("error creating file. error: %d\n", errno);
  }
}

void classExample(char *fileName) {
  int fd;
  mode_t fmode = S_IRWXU | S_IRGRP | S_IROTH; // 0744
  if ((fd = open(fileName, O_WRONLY, fmode) == -1)) {
    perror(errno);
  }
}
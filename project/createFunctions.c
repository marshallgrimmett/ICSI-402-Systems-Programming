#include <string.h>
#include <stdio.h>
#include <unistd.h> // link, symlink
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>

int createFile(char *newFile) {
  int fd;
  if ((fd = open(newFile, O_RDWR|O_CREAT, 0640)) == -1) {
    perror("Error opening file");
  }
  return fd;
}

int createDir(char *newDir) {
  int fd;
  if ((fd = mkdir(newDir, 0750)) == -1) {
    perror("Error opening directory");
  }
  return fd;
}

int createLink(char *oldFile, char *newFile) {
  int fd;
  if ((fd = link(oldFile, newFile)) == -1) {
    perror("Error creating hard link");
  }
  return fd;
}

int createSymLink(char *oldFile, char *newFile) {
  int fd;
  if ((fd = symlink(oldFile, newFile)) == -1) {
    perror("Error creating soft link");
  }
  return fd;
}

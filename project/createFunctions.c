#include <string.h>
#include <stdio.h>
#include <unistd.h> // link, symlink
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>

#define NUM_FD_ARGS 3
#define NUM_HS_ARGS 4

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

void create(int argc, char *argv[]) {
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
}
#include <stdio.h>
#include <unistd.h> // link, symlink
#include <errno.h>

void createSymLink(char *oldFile, char *newFile) {
  int fd;
  
  if ((fd = symlink(oldFile, newFile)) != -1) {
    close(fd);
  }
  else {
    printf("error creating link. error: %d\n", errno);
  }
}
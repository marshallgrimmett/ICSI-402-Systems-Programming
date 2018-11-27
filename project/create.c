#include <string.h>
#include <stdio.h>
// #include <fcntl.h>
// #include <sys/stat.h>

int createFile(char *newFile);
int createDir(char *newDir);
int createLink(char *oldFile, char *newFile);
int createSymLink(char *oldFile, char *newFile);

int main(int argc, char *argv[]) {
  create(argc, argv);
  return 0;
}

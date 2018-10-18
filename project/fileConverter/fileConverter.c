#include <stdio.h>

void fileConverter(char *fileName, char *newDir);

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Invalid number of arguments.");
    return -1;
  }
  fileConverter(argv[1], argv[2]);
  return 0;
}

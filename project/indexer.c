#include <stdio.h>

void indexer(char *indexFileName, char *dir);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Invalid number of arguments.");
    return -1;
  }
  indexer("indx.txt", "flightdata");
  return 0;
}

#include <stdio.h>

void indexer(char *indexFileName, char *dir);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Invalid number of arguments.");
    return -1;
  }
  // // check for missing index file name
  // indexer(argv[1], argv[2]);
  // indexer("indx.txt", "flightdata");
  return 0;
}

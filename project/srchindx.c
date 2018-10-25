#include <stdio.h>

void srchindx(char *flag, char *terms, char *indexFileName, char *path);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main(int argc, char *argv[]) {
  if (argc != 5) {
    printf("Invalid number of arguments.");
    return -1;
  }
  srchindx("-o", "ATL;DFW", "indx.txt", "flightdata");
  return 0;
}

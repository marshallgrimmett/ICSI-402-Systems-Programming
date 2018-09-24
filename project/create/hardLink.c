#include <stdio.h>

void hardLink(char *oldName, char *linkName) {
  FILE *linkFile = fopen(linkName, "w");
  FILE *oldFile = fopen(oldName, "r");

  // to-do

  fclose(linkFile);
  fclose(oldFile);
}
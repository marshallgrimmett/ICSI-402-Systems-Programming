#include <string.h>
#include <stdio.h>
#include <unistd.h>

#define NUM_FD_ARGS 2
#define NUM_HS_ARGS 3

void create(int argc, char *argv[]) {
  if (argc == (NUM_FD_ARGS + 1)) {
    if (strcmp(argv[1], "-f") == 0) {
      // create file
      printf("not finished.\n");
    }
    else if (strcmp(argv[1], "-d") == 0) {
      // create directory
      printf("not finished.\n");
    }
    else {
      printf("invalid command.\n");
    }
  }
  else if (argc == (NUM_HS_ARGS + 1)) {
    if (strcmp(argv[1], "-h") == 0) {
      // create hard link
      link(argv[2], argv[3]);
    }
    else if (strcmp(argv[1], "-s") == 0) {
      // create soft link
      symlink(argv[2], argv[3]);
    }
    else {
      printf("invalid command.\n");
    }
  }
  else {
    printf("invalid number of arguments.\n");
  }
}
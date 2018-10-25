#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main() {
  pid_t child = fork();
  if (child == -1) return -1;
  if (child) {
    return 0;
  }
  else {
    execlp("bin/grep", "grep", "test infile.txt", NULL);
    perror("failed.");
  }
  return 0;
}
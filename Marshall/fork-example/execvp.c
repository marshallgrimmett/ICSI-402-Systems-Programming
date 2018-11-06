#include <stdio.h>

int main() {
  pid_t child = fork();
  if (child == -1) return -1;
  if (child) {
    return 0;
  }
  else {
    execvp("ls", "ls", "-l", "infile.txt", NULL);
    perror("failed.");
  }
}
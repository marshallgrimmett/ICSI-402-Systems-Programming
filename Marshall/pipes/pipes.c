#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void printErr() {
  perror("error: ");
  exit(1);
}

int main() {
  int pd[2];
  pid_t child;
  if (pipe(pd) == 1) printErr();
  if ((child = fork()) == -1) printErr();
  if (child) {
    if (dup2(pd[1], STDOUT_FILENO) == -1) printErr();
    close(pd[0]);
    close(pd[1]);
    execlp("grep", "grep", "this", "file.txt", NULL);
    printErr();
  }
  else {
    if (dup2(pd[0], STDIN_FILENO) == -1) printErr();
    close(pd[0]);
    close(pd[1]);
    execlp("wc", "wc", "-l", NULL);
    printErr();
  }
  return 0;
}

#include <stdio.h>

int main() {
  char* getName(int);
  void setName(int, char*);
  int getId(int);
  void setId(int, int);
  int compare(int, int);
  void print(int);

  setName(0, "bob");
  setId(0, 213);
  print(0);

  return 0;
}

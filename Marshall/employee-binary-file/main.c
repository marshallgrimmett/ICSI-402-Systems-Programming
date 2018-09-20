#include <stdio.h>

int main() {
  void initDatabase();
  int addEmployees();
  void printEmployees();

  initDatabase();
  int numEmployees = addEmployees(); 
  printEmployees(numEmployees);

  return 0;
}

#include <string.h>

struct Employee {
  char name[20];
  int id;
};

struct Employee employees[50];

// int getLength() {
//   return (sizeof(employees) / sizeof(struct Employee));
// }

// void addEmployee(char name[], int id) {
//   int employeesLen = getLength();
//   if (employeesLen < 50) {
//     strcpy(employees[employeesLen].name, name);
//   }
//   else {
//     printf("Database Full :( \n");
//   }
// }

char* getName(int index) {
  return employees[index].name;
}

void setName(int index, char name[]) {
  strcpy(employees[index].name, name);
}

int getId(int index) {
  return employees[index].id;
}

void setId(int index, int id) {
  employees[index].id = id;
}

int compare(int index1, int index2) {
  if (employees[index1].id == employees[index2].id) {
    return 1;
  }
  return 0;
}

void print(int index) {
  printf("Name: %s\n", employees[index].name);
  printf("ID: %d\n", employees[index].id);
}

// void iterateAll() {
//   int employeesLen = getLength();
//   for (int i = 0; i < employeesLen; i++) {
//     printf("%s\n", employees[i]);
//   }
// }
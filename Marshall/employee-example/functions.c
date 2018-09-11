#include "externs.h"

char* getName(int i) {
  return employees[i].name;
}

void setName(int i, char name[]) {
  strcpy(employees[i].name, name);
}

int getId(int i) {
  return employees[i].id;
}

void setId(int i, char id[]) {
  employees[i].id = id;
}

int compare(int id1, int id2) {
  if (id1 == id2) {
    return 1;
  }
  return 0;
}

void print() {
  int employeeLen = sizeof(employees) / sizeof(struct employee);
  for (int i = 0; i < employeeLen; i++) {
    printf("%s\n", employees[i]);
  }
}
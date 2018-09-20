#include <stdio.h>

struct Employee {
  char name[20];
  int empid;
  float salary;
};

int main() {
  FILE *fp = fopen("emp_db.bin", "w+");
  const int size = 100;
  struct Employee employees[size];

  // initialize values in array
  for (int i = 0; i < size; i++) {
    employees[i].empid = -1;
  }

  // load array into file
  fwrite((const void *) &employees, sizeof(employees), 1, fp);

  // Prompt the user for employee info
  int i;
  for (i = 0; i < size; i++) {
    printf("\nNew Employee (type -1 to exit) ******************\n");
    printf("Enter id:");
    scanf("%d", &employees[i].empid);
    if (employees[i].empid == -1) {
      break;
    }
    printf("Enter name:");
    scanf("%s", employees[i].name);
    printf("Enter salary:");
    scanf("%f", &employees[i].salary);
  }

  printf("\n\n# of employees: %d\n\n", i);

  // load new data
  fwrite((const void *) &employees, sizeof(employees), 1, fp);

  fclose(fp);
  fp = fopen("emp_db.bin", "r+");

  // Print all employees ?
  for (int i = 0; i < size; i++) {
    printf("");
  }

  return 0;
}

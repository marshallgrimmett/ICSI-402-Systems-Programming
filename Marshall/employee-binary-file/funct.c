#include <stdio.h>

struct Employee {
  char name[20];
  int empid;
  float salary;
} temp;

const int size = 100;

//*****************************************************************************
void initDatabase() {
  FILE *fp = fopen("emp_db.bin", "w");

  temp.empid = -1;

  for (int i = 0; i < size; i++) {
    fwrite((const void*) &temp, sizeof(struct Employee), 1, fp);
  }

  // fwrite((const void*) &temp, sizeof(struct Employee), 100, fp);

  fclose(fp);
}

//*****************************************************************************
int addEmployees() {
  FILE *fp = fopen("emp_db.bin", "r+");
  int i;

  for (i = 0; i < size; i++) {
    printf("\nNew Employee (type -1 to exit) ******************\n");
    printf("Enter id:");
    scanf("%d", &temp.empid);
    if (temp.empid == -1) {
      break;
    }
    printf("Enter name:");
    scanf("%s", &temp.name);
    printf("Enter salary:");
    scanf("%f", &temp.salary);
    fwrite((const void*) &temp, sizeof(struct Employee), 1, fp);
    fseek(fp, sizeof(struct Employee), SEEK_CUR); // move to next record
  }

  printf("\n\n# of employees: %d\n\n", i);

  fclose(fp);

  return i;
}

//*****************************************************************************
void printEmployees(int numEmployees) {
  FILE *fp = fopen("emp_db.bin", "r");

  for (int i = 0; i < numEmployees; i++) {
    fread(&temp, sizeof(struct Employee), 1, fp);
    printf("\nEmployee %d ******************\n", i + 1);
    printf("id: %d\n", temp.empid);
    printf("name: %s\n", temp.name);
    printf("salary: %f\n", temp.salary);
    fseek(fp, sizeof(struct Employee), SEEK_CUR);
  }

  fclose(fp);
}
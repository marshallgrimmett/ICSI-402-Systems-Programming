#include <stdio.h>

struct Employee {
  char name[20];
  int empid;
  float salary;
} temp;

const int size = 100;
int numEmployees = 0;

//*****************************************************************************
void initDatabase() {
  FILE *fp = fopen("emp_db.bin", "w");

  temp.empid = -1;

  for (int i = 0; i < size; i++) {
    fwrite((const void*) &temp, sizeof(struct Employee), 1, fp);
  }

  fclose(fp);
}

//*****************************************************************************
void addEmployees() {
  FILE *fp = fopen("emp_db.bin", "r+");

  fseek(fp, (numEmployees * sizeof(struct Employee)), SEEK_SET); // move to last record

  for (numEmployees = numEmployees; numEmployees < size; numEmployees++) {
    printf("\nNew Employee (type -1 to exit) ******************\n");
    printf("Enter id:");
    scanf("%d", &temp.empid);
    if (temp.empid == -1) {
      break;
    }
    printf("Enter name:");
    scanf("%s", temp.name);
    printf("Enter salary:");
    scanf("%f", &temp.salary);
    fwrite((const void*) &temp, sizeof(struct Employee), 1, fp);
    fseek(fp, sizeof(struct Employee), SEEK_CUR); // move to next record
  }

  printf("\n\n# of employees: %d\n\n", numEmployees);

  fclose(fp);
}

//*****************************************************************************
void printEmployees() {
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

//*****************************************************************************
void printEmployees2() {
  FILE *fp = fopen("emp_db.bin", "r");
  int i = 0;

  do {
    fread(&temp, sizeof(struct Employee), 1, fp);
    printf("\nEmployee %d ******************\n", i + 1);
    printf("id: %d\n", temp.empid);
    printf("name: %s\n", temp.name);
    printf("salary: %f\n", temp.salary);
    fseek(fp, sizeof(struct Employee), SEEK_CUR);
    i++;
  } while(temp.empid != -1);

  fclose(fp);
}
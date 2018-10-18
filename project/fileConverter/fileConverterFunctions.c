#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>

#define SIZE_OF_BYTE 8
#define SIZE_OF_CHAR_STR 2
#define SIZE_OF_RECORD 50
#define MIN_RECORD_LEN 20

int createFile(char *newFile);
int createDir(char *newDir);
int getNumRecords(char *fileName);
void getRecords(FILE *fp, char **flights);
char getChar(FILE *fp);

void fileConverter(char *fileName, char *newDir) {
  FILE *fp;
  char **flights;
  int numRecords;

  // open file
  fp = fopen(fileName, "rb");

  // get number of records
  numRecords = getNumRecords(fileName);

  // allocate memory
  flights = (char **) malloc(numRecords * sizeof(char*));
  for (int j = 0; j < numRecords; j++) {
    flights[j] = (char *) malloc(SIZE_OF_RECORD * sizeof(char*));
  }

  // get records into array
  getRecords(fp, flights);

  // close file
  fclose(fp);

  // print each flight - TESTING
  for (int j = 0; j < numRecords; j++) {
    printf("%s\n", flights[j]);
  }

  // sort the flights by date

  // for each record, open file corresponding to airline code and append the record
  
  // free each record from memory
  for (int j = 0; j < numRecords; j++) {
    free(flights[j]);
  }
  free(flights);
}

int getNumRecords(char *fileName) {
  struct stat sb;
  if (stat(fileName, &sb) == -1) {
    perror("stat");
    exit(EXIT_FAILURE);
  }
  return (((int)sb.st_size) / SIZE_OF_BYTE / MIN_RECORD_LEN);
}

void getRecords(FILE *fp, char **flights) {
  char c;
  int i = 0, j = 0;
  while ((c = getChar(fp)) != -1) {
    if (c == '\n') {
      i++;
      // flights[i][j] = '\0';
      j = 0;
    }
    else {
      flights[i][j] = c;
      j++;
    }
  }
}

char getChar(FILE *fp) {
  char str[SIZE_OF_BYTE];
  char c;
  if (fread(str, sizeof(char), SIZE_OF_BYTE, fp) == SIZE_OF_BYTE) {
    return (c = strtol(str, 0, 2));
  }
  return -1;
}

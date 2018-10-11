#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_OF_BYTE 8
#define SIZE_OF_CHAR_STR 2
#define SIZE_OF_RECORD 50

int main() {
  FILE *fp = fopen("test.bin", "rb");
  // unsigned char str[8], // buffer to read a single binary character
  //   flights[10][50], // stores each record in an array
  //   s[2]; // stores the converted binary char

  char *str, // buffer to read a single binary character
    *flights[10], // stores each record in an array
    *s; // stores the converted binary char

  int i = 0;
  int numRecords = 10;

	//Allocate memory
	str = (char *)malloc(8);
  s = (char *)malloc(2);
  for (int j = 0; j < numRecords; j++) {
    flights[j] = (char *)malloc(50);
  }

  // add chars to each record
  while (fread(str, sizeof(char), 8, fp) == 8) {
    s[0] = strtol(str, 0, 2);
    if (s[0] == '\n') {
      i++;
    }
    else {
      strcat(flights[i], s);
    }
  }

  // close input file and free buffers
  fclose(fp);
  free(str);
  free(s);

  // print each flight - TESTING
  for (int j = 0; j < numRecords; j++) {
    printf("%s\n", flights[j]);
  }

  // sort the flights by date


  // for each record, open file corresponding to airline code and append the record
  create("./create", "-f", "AA.txt")

  // free each record from memory
  for (int j = 0; j < numRecords; j++) {
    free(flights[j]);
  }

  return 0;
}

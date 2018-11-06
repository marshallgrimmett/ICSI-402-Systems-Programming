#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

#define SIZE_OF_BYTE 8
#define SIZE_OF_CHAR_STR 2
#define SIZE_OF_RECORD 50
#define MIN_RECORD_LEN 20
#define MAX_AIRLINE_CODE 10

int createFile(char *newFile);
int createDir(char *newDir);
int getNumRecords(char *fileName);
int getRecords(FILE *fp, char **flights);
void printFlights(char **flights, int numRecords);
char getChar(FILE *fp);
void printToFiles(char **flights, int numRecords);
char *getAirline(char *record);
void bubbleSort(char **arr, const int n);

struct Date {
  int year, month, day, hour, min;
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void fileConverter(char *fileName, char *newDir) {
  FILE *fp;
  char **flights;
  int numRecords;

  // open file
  fp = fopen(fileName, "rb");

  // get number of records (estimate)
  numRecords = getNumRecords(fileName);

  // allocate memory for flights array
  flights = (char **) malloc(numRecords * sizeof(char*));
  int i;
  for (i = 0; i < numRecords; i++) {
    flights[i] = (char *) malloc(SIZE_OF_RECORD * sizeof(char*));
  }

  // get records into array (numRecords is exact number of records)
  numRecords = getRecords(fp, flights);

  // close file
  fclose(fp);

  // print each flight
  printFlights(flights, numRecords);

  // sort the flights by date
  bubbleSort(flights, numRecords);

  // create directory for files and change cwd
  createDir(newDir);
  chdir(newDir);

  // for each record, open file corresponding to airline code and append the record
  printToFiles(flights, numRecords);
  
  // free each record from memory
  int j;
  for (j = 0; j < numRecords; j++) {
    free(flights[j]);
  }
  free(flights);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int getNumRecords(char *fileName) {
  struct stat sb;
  if (stat(fileName, &sb) == -1) {
    perror("stat");
    exit(EXIT_FAILURE);
  }
  return (((int)sb.st_size) / SIZE_OF_BYTE / MIN_RECORD_LEN);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// get each record and store in flights array
int getRecords(FILE *fp, char **flights) {
  char c;
  int i = 0, j = 0;
  while ((c = getChar(fp)) != -1) {
    if (c == '\n') {
      i++;
      j = 0;
    }
    else {
      flights[i][j] = c;
      j++;
    }
  }
  flights[i][j] = '\n'; // add new line in case last record is missing it
  return (++i);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void printFlights(char **flights, int numRecords) {
  int j;
  for (j = 0; j < numRecords; j++) {
    printf("%s\n", flights[j]);
  }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// get a single char from the binary file
char getChar(FILE *fp) {
  char str[SIZE_OF_BYTE];
  char c;
  if (fread(str, sizeof(char), SIZE_OF_BYTE, fp) == SIZE_OF_BYTE) {
    return (c = strtol(str, 0, 2));
  }
  return -1;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void printToFiles(char **flights, int numRecords) {
  int fd;
  int recordLen;
  char airline[MAX_AIRLINE_CODE];
  const char *ext = ".txt";

  // put each record into a text file corresponding to the Airline
  int i;
  for (i = 0; i < numRecords; i++) {
    strcpy(airline, getAirline(flights[i]));
    strcat(airline, ext);
    fd = createFile(airline);
    lseek(fd, 0, SEEK_END);
    recordLen = strlen(flights[i]);
    write(fd, flights[i], recordLen);
    close(fd);
  }
  printf("Files created.\n");
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// gets the airline code from the record specified
char *getAirline(char *record) {
  char *airline = malloc(sizeof(char) * MAX_AIRLINE_CODE);
  int i;
  for(i = 0; i <= MAX_AIRLINE_CODE; i++) {
    if (isalpha((int) record[i]) == 0) {
      break;
    }
    airline[i] = record[i];
  }
  return airline;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// @str expected format: [yyyy-mm-dd hh:mm] e.g. [2012-03-12 11:50]
struct Date *strToDate(char *str) {
  struct Date *d = (struct Date *) malloc(sizeof(struct Date));
  d->year = atoi(strtok(str, "-"));
  d->month = atoi(strtok(NULL,"-"));
  d->day = atoi(strtok(NULL," "));
  d->hour = atoi(strtok(NULL,":"));
  d->min = atoi(strtok(NULL,""));
  return d;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// returns 0 if equal
// returns -1 if @d1 < @d2
// returns 1 if @d1 > @d2
int compareDates(struct Date *d1, struct Date *d2) {
  if (d1->year < d2->year) {return -1;}
  else if (d1->year > d2->year) {return 1;}
  else {
    if (d1->month < d2->month) {return -1;}
    else if (d1->month > d2->month) {return 1;}
    else {
      if (d1->day < d2->day) {return -1;}
      else if (d1->day > d2->day) {return 1;}
      else {
        if (d1->hour < d2->hour) {return -1;}
        else if (d1->hour > d2->hour) {return 1;}
        else {
          if (d1->min < d2->min) {return -1;}
          else if (d1->min > d2->min) {return 1;}
          else {return 0;}
        }
      }
    }
  }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// gets the date from @str and puts it into @date
void getDateStr(char *date, char *str) {
  char temp[SIZE_OF_RECORD];
  char *tempDate;
  strcpy(temp, str);
  strtok(temp, " ");
  strtok(NULL, " ");
  strtok(NULL, " ");
  strcpy(date, strtok(NULL, ""));
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void swapFlights(char *f1, char *f2) {
//   char *temp;
//   strcpy(temp, f1);
//   strcpy(f1, f2);
//   strcpy(f2, temp);
// }

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// sorts an array of flights by date
void bubbleSort(char **arr, const int n) {
  // char *date1 = (char *) malloc(sizeof(char) * MIN_RECORD_LEN);
  // char *date2 = (char *) malloc(sizeof(char) * MIN_RECORD_LEN);
  char date1[MIN_RECORD_LEN], date2[MIN_RECORD_LEN];
  char temp[SIZE_OF_RECORD];
  int i, j;
  for (i = 0; i < n-1; i++){  
    for (j = 0; j < n-i-1; j++)  {
      getDateStr(date1, arr[j]);
      getDateStr(date2, arr[j+1]);
      if (compareDates(strToDate(date1), strToDate(date2)) > 0) {
        // swapFlights(arr[j], arr[j+1]);
        strcpy(temp, arr[j]);
        strcpy(arr[j], arr[j+1]);
        strcpy(arr[j+1], temp);
      }
    } 
  }
  // free(date1);
  // free(date2);
}

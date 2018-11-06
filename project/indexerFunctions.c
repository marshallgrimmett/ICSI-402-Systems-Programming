#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
struct Airport {
  char *code;
  struct Airport *next;
  struct Record *records;
};
typedef struct Airport airport_t;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
struct Record {
  char *fileName;
  int count;
  struct Record *next;
};
typedef struct Record record_t;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
airport_t *createAirport(char* code) {
  airport_t *newAp = (airport_t*)malloc(sizeof(airport_t));
  newAp->code = code;
  newAp->next = NULL;
  newAp->records = NULL;
  return newAp;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
record_t *createRecord(char* fileName, int count) {
  record_t *newRec = (record_t*)malloc(sizeof(record_t));
  newRec->fileName = fileName;
  newRec->count = count;
  newRec->next = NULL;
  return newRec;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void indexer(char *indexFileName, char *dir) {
  // testing list
  airport_t *head = createAirport("ATL");
  head->next = createAirport("DFW");
  head->records = createRecord("AA.txt", 10);
  head->records->next = createRecord("DL.txt", 3);
  head->next->records = createRecord("DL.txt", 1);

  // TODO

  // Change to directory containing files. Try chdir()

  // PART 1
  // possible algorithm:
  // for each file. Try readdir(). (loop 1)
  //    open file
  //    for each record in each file (loop 2)
  //      get origin airport and destination airport
  //      search 2d list for the Airport, then for the Record
  //      if the Airport does not exist, createAirport(airportCode) and createRecord(fileName, 1)
  //      if the Airport exists, but Record does not, createRecord(fileName, 1)
  //      if both exist, increment the Record count
  //    close file
  // missing anything?

  // PART 2
  // Sort the Airport codes in descending order. Maybe do this in the above algorithm?
  // Sort the Records by count

  // PART 3
  // Parse the 2d list into a file with the format:
  // <list> term
  // name1 count1 name2 count2 name3 count3 name4 count4 name5 count5
  // </list>

  // close index file
}

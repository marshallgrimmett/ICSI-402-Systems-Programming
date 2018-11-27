#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "hashtable.h"

#define HT_SIZE 50

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
airport_t *hashTable[HT_SIZE];

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// int hashCode(char *key) {
//   unsigned long hash = 5381;
//   int c;
//   while ((c = *key++))
//       hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
//   return hash % HT_SIZE;
// }

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// don't know if this works?
airport_t *searchHT(char *key) {
  int hashIndex = hashFunction(key, HT_SIZE);
  while(hashTable[hashIndex] != NULL) {
    if(hashTable[hashIndex]->key == key)
      return hashTable[hashIndex]; 
    ++hashIndex;
    hashIndex %= HT_SIZE;
   }        
   return NULL;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
airport_t *createAirport(char* key) {
  airport_t *newAp = (airport_t*)malloc(sizeof(airport_t));
  newAp->key = malloc(strlen(key) + 1);
  strcpy(newAp->key, key);
  // newAp->key = key;
  newAp->chain = NULL;
  newAp->records = NULL;
  return newAp;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
record_t *createRecord(char* record) {
  record_t *newRec = (record_t*)malloc(sizeof(record_t));
  newRec->record = malloc(strlen(record) + 1);
  strcpy(newRec->record, record);
  // newRec->record = record;
  newRec->next = NULL;
  return newRec;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Can create collisions, needs chaining
void insertHT2(char *key, char *record) {
  int hashIndex = hashFunction(key, HT_SIZE);
  // if (searchHT(key) == NULL) {
  if (hashTable[hashIndex] == NULL) {
    // create new key and record
    hashTable[hashIndex] = createAirport(key);
    hashTable[hashIndex]->records = createRecord(record);
    printf("new key added, record inserted: %s\n", hashTable[hashIndex]->records->record);
  }
  else {
    // create record
    record_t *temp = createRecord(record);
    temp->next = hashTable[hashIndex]->records;
    hashTable[hashIndex]->records = temp;
    printf("record inserted: %s\n", hashTable[hashIndex]->records->record);
  }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// with chaining
void insertHT(char *key, char *record) {
  int hashIndex = hashFunction(key, HT_SIZE);
  if (hashTable[hashIndex] == NULL) {
    // create new key and record
    hashTable[hashIndex] = createAirport(key);
    hashTable[hashIndex]->records = createRecord(record);
    printf("new key added, record inserted: %s\n", hashTable[hashIndex]->records->record);
  }
  else {
    // loop through the chain
    airport_t *tempAp = hashTable[hashIndex];
    while (tempAp != NULL) {
      if (strcmp(tempAp->key, key) == 0) {
        // create record
        record_t *temp = createRecord(record);
        temp->next = tempAp->records;
        tempAp->records = temp;
        printf("record inserted: %s\n", tempAp->records->record);
      }
      tempAp = tempAp->chain;
    }
  }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// destroys the hash table so that we can start over for multiple terms
void destroyHT() {
  for (int i = 0; i < HT_SIZE; i++) {
    airport_t *tempAp = hashTable[i];
    while (tempAp != NULL) {
      free(tempAp->key);
      // delete each record
      record_t *tempRec;
      do {
        tempRec = tempAp->records;
        free(tempRec->record);
        tempAp->records = tempRec->next;
        free(tempRec);
      } while (tempRec != NULL);
      tempAp = tempAp->chain;
    }
  }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void printHT() {
  // print each record from hashtable
  for (int i = 0; i < HT_SIZE; i++) {
    airport_t *tempAp = hashTable[i];

    // if (tempAp != NULL) printf("index: %d, key: %s\n", i+1, tempAp->key);
    if (tempAp == NULL) printf("index: %d, nothing here...\n", i+1);

    // print each link in the chain
    while (tempAp != NULL) {
      record_t *tempRec = tempAp->records;

      // print each record
      while (tempRec != NULL) {
        printf("index: %d, key: %s, record: %s", i+1, tempAp->key, tempRec->record);
        tempRec = tempRec->next;
      }

      tempAp = tempAp->chain;
    }
  }
}

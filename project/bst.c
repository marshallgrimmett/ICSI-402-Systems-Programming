#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

struct Node {
  char *airline;
  int numFlights;
  struct Node *left;
  struct Node *right;
};
typedef struct Node node_t;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
struct Node *hashTable[50];

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int hashCode(char *key) {
  unsigned long hash = 5381;
  int c;
  while ((c = *key++))
      hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
  return hash % 50;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
node_t *searchHT(char *key) {
  int hashIndex = hashCode(key);
  while(hashTable[hashIndex] != NULL) {
    if(hashTable[hashIndex]->key == key)
      return hashTable[hashIndex]; 
    ++hashIndex;
    hashIndex %= 50;
   }        
   return NULL;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
node_t *createAirport(char* key) {
  node_t *newAp = (node_t*)malloc(sizeof(node_t));
  newAp->key = malloc(strlen(key) + 1);
  strcpy(newAp->key, key);
  // newAp->key = key;
  newAp->records = NULL;
  return newAp;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Can create collisions, needs chaining
void insertHT(char *key, char *record) {
  int hashIndex = hashCode(key);
  // if (searchHT(key) == NULL) {
  if (hashTable[hashIndex] == NULL) {
    // create new key and record
    hashTable[hashIndex] = createAirport(key);
    hashTable[hashIndex]->records = createRecord(record);
    printf("new key added, record inserted: %s\n", hashTable[hashIndex]->records->record);
  }
  else {
    // create record
    struct Record *temp = createRecord(record);
    temp->next = hashTable[hashIndex]->records;
    hashTable[hashIndex]->records = temp;
    printf("record inserted: %s\n", hashTable[hashIndex]->records->record);
  }
}

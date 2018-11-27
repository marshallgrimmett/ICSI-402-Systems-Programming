#ifndef HASHTABLE
#define HASHTABLE

int hashFunction(char *s,  int T);
void insertHT(char *key, char *record);
void printHT();

struct Airport {
  char *key;
  struct Airport *chain;
  struct Record *records;
};
typedef struct Airport airport_t;

struct Record {
  char *record;
  struct Record *next;
};
typedef struct Record record_t;

#endif
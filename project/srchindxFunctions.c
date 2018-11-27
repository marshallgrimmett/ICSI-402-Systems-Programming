#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ftw.h>

#include "hashtable.h"

// These variables are global since I could not find a way
// to pass them into ftw()
char *flag, *terms, *indexFileName, *path;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// This gets the count for the filename in the index file with the term
int getIndexCount(char *term, char *path) {
  FILE *fp = fopen(indexFileName, "r");
  size_t lineLen = 80;
  char *line;

  if (fp == NULL) {
    perror("error:");
    exit(1);
  }

  if((line = (char *)malloc(lineLen * sizeof(char))) == NULL) {
    perror("Unable to allocate buffer");
    exit(1);
  }

  while (getline(&line, &lineLen, fp) != -1) {
    if (strstr(line, term) != NULL) { // check if line contains the term
      getline(&line, &lineLen, fp);
      char *token = strtok(line, " ");
      while (token != NULL) {
        if (strcmp(token, path) == 0) {
          token = strtok(NULL, " ");
          fclose(fp);
          return atoi(token);
        }
        token = strtok(NULL, " ");
      }
    }
  }

  fclose(fp);
  return -1;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Searches a file for the term in each record.
// If the flag is '-o' it will only search origin airports and add it to the hashtable.
// If the flag is '-d' it will only search destination airports and add it to the BST.
void searchTerm(char *term, int count) {
  FILE *fp = fopen(path, "r");
  size_t lineLen = 0;
  char *line = NULL;

  if (fp == NULL) {
    perror("error opening file");
    exit(1);
  }

  // if((line = (char *)malloc(lineLen * sizeof(char))) == NULL) {
  //   perror("Unable to allocate buffer");
  //   exit(1);
  // }

  while ((getline(&line, &lineLen, fp) != -1) && count > 0) {
  // while (count > 0) {
    // getline(&line, &lineLen, fp);
    char temp[lineLen];
    strcpy(temp, line);
    char *token = strtok(temp, " ");
    token = strtok(NULL, " ");
    if (strcmp(flag, "-d") == 0) {
      token = strtok(NULL, " ");
    }
    if (strcmp(token, term) == 0) {
      // insert line into hashtable or bst
      // hashtable, key = basename(path), insert into linked list at key
      insertHT(term, line);
      // int test = hashCode(term);
      // printf("term: %s\n", term);
      // printf("hashcode: %d\n", test);
      // printf("inserted record: %s", line);
      count--;
    }
    free(line);
    line = NULL;
  }

  fclose(fp);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// For each term, get the index count for the current file,
// then search for the term in the current file.
void parseTerms() {
  int count = 0;
  char *term;
  char temp[strlen(terms)];
  strcpy(temp, terms);
  char *rest = temp;

  // gets the number of occurences of the term for the file
  term = strtok_r(rest, ",", &rest);
  while (term != NULL) {
    // The following makes use of the count but needs to pass it to searchTerm
    // This allows the loop to exit early, at the cost of searching the index file
    // Doesn't seem worth it, but then what is the purpose of the index file?
    count = getIndexCount(term, basename(path));
    // search file for term in destination
    searchTerm(term, count);
    term = strtok_r(rest, ",", &rest);
  }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int list(const char *name, const struct stat *status, int type) {
  if (type == FTW_NS)
    return 0;
  
  if (type == FTW_F) {
    path = (char *) name;
    parseTerms(); 
  }

  return 0;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void srchindx(int argc, char *argv[]) {
  struct stat pathStat;

  if (argc != 5) {
    printf("Invalid number of arguments.");
    exit(1);
  }

  // may need to strcpy values
  flag = argv[1];
  terms = argv[2];
  indexFileName = argv[3];
  path = argv[4];

  stat(path, &pathStat);

  // Check if file or directory
  if (S_ISREG(pathStat.st_mode)) {
    parseTerms();
  }
  else if (S_ISDIR(pathStat.st_mode)) {
    ftw(path, list, 1);
  }
  else {
    perror("error, not a file or directory");
    exit(1);
  }

  printHT();
}

/*
Questions:
  - based on the flag, you only want hashtable OR BST, not both?
  - You want a hashtable for EACH term? But the keys in the hashtable ARE the terms.
    So each hashtable will have only 1 key with a chain of records to it?


Hashtable for each term?
In the document it says that we need a hashtable for each term, but each term is a key in the hashtable. So won't this result in multiple hashtables with one key each?
Also, each element in the hashtable will have a key(origin airport) and a record correct? Since multiple records can have the same origin airport, won't there be duplicate keys in the table?


// PART 1
// if flag is -o, create a hashtable
// Construct hashtable

// PART 2
// if flag is -d, create a BST
// construct BST

// Construct BST or hashtable for each of the terms


// The next parts need work


// PART 3
// function to recursively search directory (and subdirectories) for files.

// PART 4
// for each term
//    find the term in the index file
//    search each record for the term(airport), based on the flag (-o search origin airports only)
//      if the term matches, add the record to the BST or hashtable
//    stop searching once the count is hit
// missing anything?

// PART 7
// Need function(s) for retrieving elements from strings.
// I.e. retrieve airport code from a record

// PART 6
// Print the contents of the BST or hashtable
*/

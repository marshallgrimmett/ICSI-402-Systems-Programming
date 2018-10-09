#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Link {
  int value;
  char *key;
  struct Link *next;
};
typedef struct Link link_t;

link_t* create_link(char* key, int value);

int main() {
  link_t* head = create_link("this is a key", 5);

  head->next = create_link("something", 2);

  // print linked list
  link_t* temp = head;
  while (temp != NULL) {
    printf("%d\n", temp->value);
    printf("%s\n", temp->key);
    temp = temp->next;
  }

  // deallocate
  while (head != NULL) {
    temp = head;
    head = temp->next;
    free(temp);
  }

  return 0;
}

link_t* create_link(char* key, int value) {
  link_t *newLink = (link_t*)malloc(sizeof(link_t));

  newLink->value = value;
  newLink->key = key;
  newLink->next = NULL;

  return newLink;
}
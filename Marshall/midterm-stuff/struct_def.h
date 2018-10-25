#ifndef STRUCT_DEF_H
#define STRUCT_DEF_H

struct key_record {
  int value; struct key_record *next;
};
typedef struct key_record* keyptr;

#endif

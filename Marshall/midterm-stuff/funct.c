#include <stdio.h>
#include <stdlib.h>
#include "struct_def.h"
#include "externs.h"

keyptr doSomething() {
  keyptr head = (keyptr)malloc(sizeof(keyptr));
  head->value = 5;
  printf("%d\n", head->value);
  return head;
}
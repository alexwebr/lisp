#include "parser.h"

#ifndef _STACK_H
#define _STACK_H

typedef struct stack_t {
  struct stack_t *previous;
  tree_t *node;
} stack_t;

void *peek(void);
void *pop(void);
void push(void *node);

#endif

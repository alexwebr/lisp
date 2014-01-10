#include "parser.h"

#ifndef _STACK_H
#define _STACK_H

typedef struct stack_t {
  struct stack_t *previous;
  tree_t *node;
} stack_t;

tree_t *peek(void);
tree_t *pop(void);
void push(tree_t *node);

#endif

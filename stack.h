#include "parser.h"

#ifndef _STACK_H
#define _STACK_H

typedef struct stack_t {
  struct stack_t *previous;
  tree_node_t *node;
} stack_t;

#endif

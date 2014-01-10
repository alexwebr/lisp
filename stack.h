#include "parser.h"

#ifndef _STACK_H
#define _STACK_H

typedef struct stack_t {
  struct stack_t *next;
  tree_t *data;
} stack_t;

void *peek(stack_t *stack);
void *pop(stack_t *stack);
void push(stack_t *stack, void *data);
void free_stack(stack_t *stack);

#endif

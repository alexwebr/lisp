#include "stack.h"
#include "parser.h"

static stack_t *stack = NULL;

void push(void *node)
{
  stack_t *p = malloc(sizeof(stack_t));
  p->node = node;
  p->previous = stack;
  stack = p;
}

void *peek(void)
{
  if (stack == NULL)
    return NULL;

  return stack->node;
}

void *pop(void)
{
  if (stack == NULL)
    return NULL;

  // Save before freeing and returning
  stack_t *p = stack;
  void *node = p->node;

  stack = stack->previous;
  free(p);
  return node;
}

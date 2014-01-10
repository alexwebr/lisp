#include "stack.h"
#include "parser.h"

static stack_t *stack = NULL;

void push(void *data)
{
  stack_t *p = malloc(sizeof(stack_t));
  p->data = data;
  p->previous = stack;
  stack = p;
}

void *peek(void)
{
  if (stack == NULL)
    return NULL;

  return stack->data;
}

void *pop(void)
{
  if (stack == NULL)
    return NULL;

  // Save before freeing and returning
  stack_t *p = stack;
  void *data = p->data;

  stack = stack->previous;
  free(p);
  return data;
}

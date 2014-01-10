#include "stack.h"
#include "parser.h"

static stack_t *stack = NULL;

void push(tree_t *node)
{
  stack_t *p = malloc(sizeof(stack_t));
  p->node = node;
  p->previous = stack;
  stack = p;
}

tree_t *peek(void)
{
  if (stack == NULL)
    return NULL;

  return stack->node;
}

tree_t *pop(void)
{
  if (stack == NULL)
    return NULL;

  // Save before freeing and returning
  stack_t *p = stack;
  tree_t *node = p->node;

  stack = stack->previous;
  free(p);
  return node;
}

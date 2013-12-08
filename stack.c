#include "stack.h"
#include "parse.h"

static stack_t *stack = NULL;

void push(tree_node_t *node)
{
  stack_t *p = malloc(sizeof(stack_t));
  p->node = node;
  p->previous = stack;
  stack = p;
}

tree_node_t *peek(void)
{
  if (stack == NULL)
    return NULL;

  return stack->node;
}

tree_node_t *pop(void)
{
  if (stack == NULL)
    return NULL;

  // Save before freeing and returning
  stack_t *p = stack;
  tree_node_t *node = p->node;

  stack = stack->previous;
  free(p);
  return node;
}

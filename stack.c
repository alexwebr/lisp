#include "stack.h"
#include "parser.h"

void push(stack_t *stack, void *data)
{
  while (stack->next != NULL)
    stack = stack->next;

  stack->next = malloc(sizeof(stack_t));
  stack->next->next = NULL;
  stack->next->data = data;
}

void *peek(stack_t *stack)
{
  while (stack->next != NULL)
    stack = stack->next;

  return stack->data;
}

void *pop(stack_t *stack)
{
  if (stack->next == NULL)
    return NULL;

  while (stack->next->next != NULL)
    stack = stack->next;

  void *data = stack->next->data;

  free(stack->next);
  stack->next = NULL;

  return data;
}

void free_stack(stack_t *stack)
{
  while (pop(stack) != NULL);
  free(stack);
}

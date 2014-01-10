#include "parser.h"

// Recursive function that prints the tree :)
void print_tree(unsigned int depth, tree_t *p)
{
  // Print the indentation
  unsigned int i = 0;
  for (i = 0; i < depth; ++i)
    printf("  ");

  if (p->type == NODE_ROOT)
    puts("ROOT");

  if (p->type == NODE_ATOM)
    puts("ATOM");

  if (p->type == NODE_SEXPR)
    puts("SEXPR");

  if (p->child == NULL)
    return;

  // Depth-first
  print_tree(depth + 1, p->child);

  p = p->child;
  while (p->sibling != NULL) {
    p = p->sibling;
    print_tree(depth + 1, p);
  }
}

void free_tree(tree_t *p)
{
  if (p->sibling != NULL) {
    free_tree(p->sibling);
    p->sibling = NULL;
  }

  if (p->child != NULL) {
    free_tree(p->child);
    p->child = NULL;
  }

  free(p);
}

int main()
{
  char buf[100000];

  int c = 0;
  unsigned int i = 0;
  while ((c = getchar()) != EOF)
    buf[i++] = c & 0xFF;

  tree_t *p = create_parse_tree(buf, i);
  print_tree(0, p);
  free_tree(p);
}

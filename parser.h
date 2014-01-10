#include "lexer.h"

#ifndef _PARSE_H
#define _PARSE_H

typedef struct tree_t {
  enum {
    NODE_ROOT,
    NODE_SEXPR,
    NODE_ATOM,
  } type;
  struct tree_t *child;
  struct tree_t *sibling;
  token_t token;
} tree_t;

void append_child(tree_t *parent, tree_t *child);
tree_t *create_parse_tree(char *buf, unsigned int buflen);

#endif

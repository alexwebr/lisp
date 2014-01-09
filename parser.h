#include "lexer.h"

#ifndef _PARSE_H
#define _PARSE_H

typedef struct tree_node_t {
  enum {
    NODE_ROOT,
    NODE_SEXPR,
    NODE_ATOM,
  } type;
  struct tree_node_t *child;
  struct tree_node_t *sibling;
  token_t token;
} tree_node_t;

#endif

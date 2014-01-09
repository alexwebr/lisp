#include "parser.h"

void append_child(tree_node_t *parent, tree_node_t *child)
{
  if (parent->child == NULL) {
    parent->child = child;
    return;
  }

  tree_node_t *p = parent->child;

  while (p->sibling != NULL)
    p = p->sibling;

  p->sibling = child;
}

tree_node_t *create_parse_tree(char *buf, unsigned int buflen)
{
  // Tree initialization
  tree_node_t *root = malloc(sizeof(tree_node_t));
  root->type = NODE_ROOT;
  root->child = NULL;
  root->sibling = NULL;

  // Stack initialization
  push(root);

  // Temporary pointer
  tree_node_t *p;

  while (1) {
    token_t token = lex_get_tok(buf, buflen);

    switch (token.type) {
      case TOK_LPAREN:
        p = malloc(sizeof(tree_node_t));
        p->child = NULL;
        p->sibling = NULL;
        p->type = NODE_SEXPR;

        append_child(peek(), p);
        push(p);

        break;


      case TOK_IDENT:
      case TOK_INTEGER:
      case TOK_STRING:
        p = malloc(sizeof(tree_node_t));
        p->type = NODE_ATOM;
        p->token = token;

        append_child(peek(), p);

        break;


      case TOK_RPAREN:
        pop();

        if (peek() == NULL) {
          puts("Closed non-existent sexpr");
          exit(1);
        }

        break;


      case TOK_EOF:
        if (peek()->type != NODE_ROOT) {
          puts("Unclosed sexpr");
          exit(1);
        }

        return root;
        break;
    }
  }
}

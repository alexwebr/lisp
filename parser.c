#include "parser.h"
#include "stack.h"

void append_child(tree_t *parent, tree_t *child)
{
  if (parent->child == NULL) {
    parent->child = child;
    return;
  }

  tree_t *p = parent->child;

  while (p->sibling != NULL)
    p = p->sibling;

  p->sibling = child;
}

tree_t *create_parse_tree(char *buf, unsigned int buflen)
{
  // Tree initialization
  tree_t *root = malloc(sizeof(tree_t));
  root->type = NODE_ROOT;
  root->child = NULL;
  root->sibling = NULL;

  // Stack initialization
  push(root);

  // Temporary pointer
  tree_t *p;

  while (1) {
    token_t token = lex_get_tok(buf, buflen);

    switch (token.type) {
      case TOK_LPAREN:
        p = malloc(sizeof(tree_t));
        p->child = NULL;
        p->sibling = NULL;
        p->type = NODE_SEXPR;

        append_child(peek(), p);
        push(p);

        break;


      case TOK_IDENT:
      case TOK_INTEGER:
      case TOK_STRING:
        p = malloc(sizeof(tree_t));
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
        if (((tree_t *) peek())->type != NODE_ROOT) {
          puts("Unclosed sexpr");
          exit(1);
        }

        // Validate that there are no atoms at the top level
        p = root->child;
        while (p != NULL) {
          if (p->type == NODE_ATOM) {
            puts("Atom outside of sexpr");
            exit(1);
          }
          p = p->sibling;
        }

        return root;
        break;
    }
  }
}

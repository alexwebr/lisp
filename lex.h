#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef _LEX_H
#define _LEX_H

typedef struct {
  enum {
    TOK_EOF,
    TOK_IDENT,
    TOK_INTEGER,
    TOK_LPAREN,
    TOK_RPAREN,
    TOK_STRING
  } type;
  unsigned int starti;
  unsigned int endi;
} token_t;

token_t lex_get_tok(char *buf, unsigned int buflen);

typedef enum {
  STATE_S,
  STATE_STRING,
  STATE_INTEGER,
  STATE_IDENT
} lexer_state;

#endif

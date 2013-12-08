#include "lex.h"
#include <string.h>
#include <stdlib.h>

char *ident_alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
char *integer_alphabet = "0123456789";
char *skip_alphabet = "\t\n\r ";
char *transition_alphabet = "\t\n\r ()";

token_t lex_get_tok(char *buf, unsigned int buflen)
{
  static unsigned int ci = 0;
  unsigned int tok_start = ci;

  lexer_state state = STATE_S;

  while (ci < buflen) {
    char c = buf[ci++];

    switch (state) {
      case STATE_S:
        if (c == '"')
          state = STATE_STRING;

        if (c == '(')
          return (token_t) { .type = TOK_LPAREN, .starti = ci - 1, .endi = ci };

        if (c == ')')
          return (token_t) { .type = TOK_RPAREN, .starti = ci - 1, .endi = ci };

        if (strchr(ident_alphabet, c))
          state = STATE_IDENT;

        if (strchr(integer_alphabet, c))
          state = STATE_INTEGER;

        if (state != STATE_S)
          tok_start = ci;

        break;


      case STATE_STRING:
        if (c == '"')
          return (token_t) { .type = TOK_STRING, .starti = tok_start, .endi = ci };

        if (!isprint(c)) {
          buf[ci] = '\0';
          printf("Illegal character in string, valid part shown: %s\n", &buf[ci - 1]);
          exit(1);
        }

        break;


      case STATE_IDENT:
        if (strchr(transition_alphabet, c))
          return (token_t) { .type = TOK_IDENT, .starti = tok_start, .endi = ci-- };

        if (!strchr(ident_alphabet, c)) {
          buf[ci] = '\0';
          printf("Illegal character in ident, valid part shown: %s\n", &buf[ci - 1]);
          exit(1);
        }

        break;


      case STATE_INTEGER:
        if (strchr(transition_alphabet, c))
          return (token_t) { .type = TOK_INTEGER, .starti = tok_start, .endi = ci-- };

        if (!strchr(integer_alphabet, c)) {
          buf[ci] = '\0';
          printf("Illegal character in integer, valid part shown: %s\n", &buf[ci - 1]);
          exit(1);
        }

        break;
    }
  }

  if (state == STATE_IDENT)
    return (token_t) { .type = TOK_IDENT, .starti = tok_start, .endi = ci };

  if (state == STATE_INTEGER)
    return (token_t) { .type = TOK_INTEGER, .starti = tok_start, .endi = ci };

  if (state == STATE_STRING) {
    puts("Reached end-of-file with an unterminated string");
    exit(1);
  }

  if (state == STATE_S)
    return (token_t) { .type = TOK_EOF, .starti = ci, .endi = ci };
}

#include "lex.h"

int main()
{
  char buf[100000];

  int c = 0;
  unsigned int i = 0;
  while ((c = getchar()) != EOF)
    buf[i++] = c & 0xFF;

  while (1) {
    token_t token = lex_get_tok(buf, i);

    switch(token.type) {
      case TOK_EOF:
        puts("EOF");
        exit(0);
        break;

      case TOK_IDENT:
        puts("IDENT");
        break;

      case TOK_INTEGER:
        puts("INTEGER");
        break;

      case TOK_LPAREN:
        puts("LPAREN");
        break;

      case TOK_RPAREN:
        puts("RPAREN");
        break;

      case TOK_STRING:
        puts("STRING");
        break;

      default:
        printf("SOMETHING ELSE: %d\n", token.type);
        break;
    }
  }
}

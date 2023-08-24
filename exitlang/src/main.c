#include <stdio.h>

#include "lexer.h"
#include "tokenlist.h"

#define VALID_SOURCE 1

int main(void) {
#if VALID_SOURCE
  const char *source = "# Simple program that exits with code 69.\n"
                       "69\n";
#else
  const char *source = "# Simple program that exits with code 69.\n"
                       "exit(69);\n";
#endif

  TokenList tokens = token_list_new();
  if (tokenize(source, &tokens) == 1) {
    return 1;
  }
  printf("%ld\n", token_list_at(&tokens, 0)->value);

  return 0;
}

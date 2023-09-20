#include "lexer.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static const char *skip_comment(const char *source) {
  const char *it = source;
  while (*it != '\0' && *it != '\n') {
    ++it;
  }
  return ++it;
}

static int tokenize_character(const char **source) {
  switch (**source) {
  case '#':
    *source = skip_comment(*source);
    break;
  default:
    if (is_digit(**source)) {
      // Iterate through, determine length of numeric section
      // Copy that part of the string into conversion func
      size_t length = 0;
      char *dest;
      long number;

      do {
        ++length;
        ++source;
      } while (is_digit(*source));

      dest = malloc(length);
      if (dest == NULL) {
        return 1;
      }

      strncpy(dest, source - length, length);
      number = strtol(dest, NULL, 10);
      token_list_push(out_tokens, number);
      free(dest);
    } else if (!is_space(*source)) {
      return 1;
    }
    ++source;
    break;
  }
  return 0;
}

bool is_digit(char c) {
  return '0' <= c && c <= '9';
}

bool is_space(char c) {
  return c == '\t'  // Horizontal tab
    || c == '\n'    // Newline
    || c == '\v'    // Vertical tab
    || c == '\f'    // Formfeed
    || c == '\r'    // Carriage return
    || c == ' ';    // Space
}

int tokenize(const char *source, TokenList *out_tokens) {
  // Iterate through source
  while (*source != '\0') {
    if (tokenize_character(&source)) {
      return 1;
    }
  }
  return 0;
}

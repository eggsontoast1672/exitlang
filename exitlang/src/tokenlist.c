#include "tokenlist.h"

#include <stdlib.h>

Token *token_list_at(TokenList *tokens, size_t index) {
  // TODO: Handle index out of range
  return &tokens->data[index];
}

TokenList token_list_new(void) {
  return (TokenList){
    .data = NULL,
    .size = 0,
    .capacity = 0,
  };
}

void token_list_push(TokenList *tokens, long value) {
  // 1. If there's not enough space, reallocate
  // 2. Construct the token and add it to the end
  // 3. Increment size
  if (tokens->capacity < tokens->size + 1) {
    size_t new_capacity = tokens->capacity ? tokens->capacity * 2 : sizeof(Token);
    Token *new_block = realloc(tokens->data, new_capacity);
    if (new_block == NULL) {
      // TODO: Handle realloc failure
    }
    tokens->data = new_block;
    tokens->capacity = new_capacity;
  }
  tokens->data[tokens->size++] = (Token){ .value = value };
}

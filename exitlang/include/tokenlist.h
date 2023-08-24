#pragma once

#include <stdlib.h>

typedef struct {
  long value;
} Token;

typedef struct {
  Token *data;
  size_t size;
  size_t capacity;
} TokenList;

/// Gets a pointer to a token at a certain index.
///
/// @param[in] tokens The token list whose element is to be gotten.
/// @param index The index of the token to get.
Token *token_list_at(TokenList *tokens, size_t index);

/// Creates a new TokenList.
/// 
/// @return If the function succeeds, the pointer passed as this parameter will
///         be filled with a valid TokenList. Otherwise, its value is not
///         guaranteed.
TokenList token_list_new(void);

/// Add a token to the list.
/// 
/// @param[in] tokens The token list to which to add the new token.
/// @param value The value of the token to be added to the list.
void token_list_push(TokenList *tokens, long value);

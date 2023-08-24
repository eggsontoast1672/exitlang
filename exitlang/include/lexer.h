#pragma once

#include <stdbool.h>

#include "tokenlist.h"

/// Returns true if c is a digit character (e.g. 0-9), and false otherwise.
bool is_digit(char c);

/// Returns true if c is a whitespace character (e.g. tab, newline, space,
/// etc.), and false otherwise.
bool is_space(char c);

/// Converts some source code into tokens.
/// 
/// @param[in] source A pointer to the null-terminated source code to be
///                   tokenized.
/// @param[out] tokens If the function succeeds, the pointer passed as this
///                    parameter will be filled with a valid TokenList
///                    containing the tokens in source. Otherwise, its value is
///                    not guaranteed.
/// 
/// @return The result of the operation. R_OK on success, or something else on
///         failure.
int tokenize(const char *source, TokenList *tokens);

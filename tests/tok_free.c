#include "main.h"

/**
 * tok_free - Function that frees the tokens.
 *
 * @tokens: tokens.
 */

void tok_free(char **tokens)
{
	int t;

	for (t = 0; tokens[t] != NULL; t++)
		free(tokens[t]);
	free(tokens);
}

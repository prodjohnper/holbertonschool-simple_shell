#include "main.h"

/**
 * free_arrays - Function that frees the tokens.
 *
 * @tokens: tokens.
 */

void free_arrays(char **tokens)
{
	int t;

	for (t = 0; tokens[t] != NULL; t++)
		free(tokens[t]);
	free(tokens);
}

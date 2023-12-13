#include "main.h"

/**
 * tokenizer - Function that tokenizes a
 * string into an array of strings.
 *
 * @line_str: string to tokenize.
 *
 * Return: an array of strings.
 */

char **tokenizer(char *line_str)
{
	char *token, *dup_str, **tokens = NULL;
	int i, token_count = 0;

	dup_str = strdup(line_str);
	if (!dup_str)
	{
		return (NULL);
	}
	token = strtok(dup_str, " ");
	while (token)
	{
		token_count++;
		token = strtok(NULL, " ");
	}
	tokens = malloc((token_count + 1) * sizeof(char *));
	if (!tokens)
	{
		free(dup_str);
		return (NULL);
	}
	dup_str = strdup(line_str);
	token = strtok(dup_str, " ");
	for (i = 0; i < token_count; i++)
	{
		tokens[i] = strdup(token);
		if (!tokens[i])
		{
			free(dup_str);
			tok_free(tokens);
			return (NULL);
		}
		token = strtok(NULL, " ");
	}
	tokens[i] = NULL;

	free(dup_str);
	return (tokens);
}

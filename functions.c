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
			free_arrays(tokens);
			return (NULL);
		}
		token = strtok(NULL, " ");
	}
	tokens[i] = NULL;

	free(dup_str);
	return (tokens);
}

/**
 * command - Function that prints command errors.
 *
 * @line_str: pointer.
 */

void command(char *line_str)
{
	int stat;
	char **args;
	pid_t pid;

	args = tokenizer(line_str);
	if (args == NULL)
	{
		fprintf(stderr, "Error while tokenizing input\n");
		return;
	}

	if (access(args[0], X_OK) == -1)
	{
		perror("access");
		fprintf(stderr, "Command '%s' not found\n", args[0]);
		free_arrays(args);
		return;
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free_arrays(args);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execve(args[0], args, NULL);
		perror("execve");
		free_arrays(args);
	}
	else
	{
		waitpid(pid, &stat, 0);
		free_arrays(args);
	}
}

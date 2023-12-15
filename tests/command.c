#include "main.h"

/**
 * command - Function that prints command errors.
 *
 * @line_str: pointer.
 */

void command(char *line_str)
{
	int stat;
	char **args = NULL;
	pid_t pid;

	args = tokenizer(line_str);
	if (args == NULL)
	{
		fprintf(stderr, "Error while tokenizing input\n");
		return;
	}

	printf("Executing command: %s\n", args[0]);
	if (access(args[0], X_OK) == -1)
	{
		perror("access");
		fprintf(stderr, "Command '%s' not found\n", args[0]);
		tok_free(args);
		return;
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		tok_free(args);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execve(args[0], args, NULL);
		perror("execve");
		tok_free(args);
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &stat, 0);
		tok_free(args);
	}
}

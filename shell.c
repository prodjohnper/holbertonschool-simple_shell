#include "main.h"

/**
 * main - Shell program.
 *
 * Return: 0.
 */

int main(void)
{
	char *line_str = NULL;
	size_t len = 0;
	ssize_t read_bytes;
	int on = 1;
	char **args;

	while (on != 0)
	{
		if (isatty(STDIN_FILENO))
			printf("($) ");
		read_bytes = getline(&line_str, &len, stdin);
		if (read_bytes == -1)
		{
			on = 0;
		}
		else
		{
			if (line_str[read_bytes - 1] == '\n')
			{
				line_str[read_bytes - 1] = '\0';
				read_bytes--;
			}
			if (strcmp(line_str, "exit") == 0)
				on = 0;
			else
			{
				command(line_str);
			}
			if (access(args[0], X_OK) == 0)
				command(args, environ);
			else
				getpath(args, environ);
			if (access(args[0], X_OK) != 0)
				perror(args, line_str);
			tok_free(args);
		}
		if (!isatty(STDIN_FILENO))
			fflush(stdout);
		else
			printf("\n");
	}
	free(line_str);
	return (0);
}

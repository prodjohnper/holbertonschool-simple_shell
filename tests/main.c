#include "main.h"

/**
 * main - Simple Shell Program.
 *
 * @argc: arguments count.
 * @argv: arguments
 *
 * Return: 0.
 */

int main(int argc, char **argv)
{
	char *prompt = "($) ";
	char *line = NULL, *line_copy = NULL, *token;
	size_t len = 0;
	ssize_t chars_read;
	const char *limiter = " \n";
	int num_tokens = 0, i;

	(void)argc;

	while (1)
	{
		printf("%s", prompt);
		chars_read = getline(&line, &len, stdin);
		if ((chars_read == -1 || strcmp(line, "Exit") == 0))
		{
			printf("Exit\n");
			return (-1);
		}

		line_copy = malloc(sizeof(char) * chars_read);
		if (line_copy == NULL)
		{
			perror("Error: couldn't allocate memory");
			return (-1);
		}

		strcpy(line_copy, line);

		token = strtok(line, limiter);

		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, limiter);
		}
		num_tokens++;

		argv = malloc(sizeof(char *) * num_tokens);

		token = strtok(line_copy, limiter);

		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);

			token = strtok(NULL, limiter);
		}
		argv[i] = NULL;

		printf("%s\n", line);
	
		free(line);
	}
	return (0);
}

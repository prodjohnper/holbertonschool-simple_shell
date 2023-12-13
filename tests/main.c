#include "main.h"

/**
 * main - Simple Shell Program.
 *
 * Return: 0.
 */

int main()
{
	char *line = NULL, *token;
	size_t len = 0;
	ssize_t chars_read;
	int num_tokens = 0;
	int on = 1;

	while (on != 0)
	{
		printf("($) ");
		chars_read = getline(&line, &len, stdin);

		if (chars_read == -1)
		{
			printf("\n");
			on = 0;
		}
		else if (strcmp(line, "exit\n") == 0)
		{
			on = 0;
		}
		else
		{
			line[chars_read - 1] = '\0';
			chars_read--;

			token = strtok(line, " ");
			while (token != NULL)
			{
				num_tokens++;
				printf("%s\n", token);
				token = strtok(NULL, " ");
			}
		}
	}
	free(line);
	return (0);
}

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

	while (on != 0)
	{
		if (isatty(STDIN_FILENO))
			printf("($) ");
		read_bytes = getline(&line_str, &len, stdin);
		if (read_bytes == -1)
		{
			if (isatty(fileno(stdin)) == -1)
				printf("\n");
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
		}
		/* if (!isatty(STDIN_FILENO))
			 fflush(stdout); */
	}
	free(line_str);
	return (0);
}

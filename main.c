#include "shell.h"

/**
 * main - Entry point for simple shell
 * Return: Always 0
 */
int main(void)
{
	char *line;
	int interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (interactive)
			display_prompt();

		line = read_line();

		if (line == NULL)
		{
			if (interactive)
				printf("\n");
			break;
		}

		if (line[0] != '\0')
			execute_cmd(line);

		free(line);
	}

	return (0);
}
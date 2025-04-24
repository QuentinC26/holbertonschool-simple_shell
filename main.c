#include "shell.h"

/**
 * main - Entry point for simple shell
 * Return: Always 0
 */
int main(void)
{
	char *line;

	while (1)
	{
		display_prompt();
		line = read_line();

		if (line == NULL) /* Ctrl+D */
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}

		if (line[0] != '\0')
			execute_cmd(line);

		free(line);
	}

	return (0);
}

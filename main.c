#include "shell.h"

/**
 * main - Entry point for simple shell
 * Return: Always 0
 */
int main(void)
{
	char *line;
	int is_interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (is_interactive)
			display_prompt();
		line = read_line();

		if (line == NULL) /* Ctrl+D */
		{
			if (is_interactive)
				write(STDOUT_FILENO, "\n", 1);
			break;
		}
		if (strcmp(line, "exit") == 0)
		{
			free(line);
			break;
		}
		if (strcmp(line, "\n") == 0)
		{
			free(line);
			continue;
		}
		if (line[0] != '\0')
			execute_cmd(line);

		free(line);
	}

	return (0);
}

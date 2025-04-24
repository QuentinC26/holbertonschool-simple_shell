#include "shell.h"

/**
 * execute_cmd - Exécute une commande avec arguments
 * @line: ligne de commande (non NULL)
 */
void execute_cmd(char *line)
{
	pid_t pid;
	char **argv = tokenize_line(line);

	if (argv[0] == NULL)
	{
		free(argv);
		return;
	}

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		free(argv);
		return;
	}

	if (pid == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
		free(argv);
	}
}

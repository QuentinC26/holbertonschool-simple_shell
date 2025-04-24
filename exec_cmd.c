#include "shell.h"

/**
 * execute_cmd - Lance la commande avec execve
 * @line: commande entrée par l’utilisateur (chemin complet)
 */
void execute_cmd(char *line)
{
	pid_t pid;
	char *argv[2];

	argv[0] = line;
	argv[1] = NULL;

	pid = fork();

	if (pid == -1)
	{
		perror("Error");
		return;
	}

	if (pid == 0)
	{
		/* Enfant */
		if (execve(argv[0], argv, environ) == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent */
		wait(NULL);
	}
}

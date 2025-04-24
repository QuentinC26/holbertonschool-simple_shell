#include "shell.h"

/**
 * handle_builtin - Gère les commandes internes comme "exit"
 * @argv: tableau des arguments
 * Return: 1 si un builtin a été exécuté, 0 sinon
 */
int handle_builtin(char **argv)
{
	if (!argv || !argv[0])
		return (0);

	if (strcmp(argv[0], "exit") == 0)
	{
		free(argv);
		exit(0);
	}

	return (0);
}

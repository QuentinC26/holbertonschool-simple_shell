#include "shell.h"

/**
 * handle_builtin - Gère les commandes internes comme "exit" et "env"
 * @argv: tableau des arguments
 * Return: 1 si un builtin a été exécuté, 0 sinon
 */
int handle_builtin(char **argv)
{
	int count;

	if (!argv || !argv[0])
		return (0);

	if (strcmp(argv[0], "exit") == 0)
	{
		free(argv);
		exit(0);
	}

	if (strcmp(argv[0], "env") == 0)
	{
		for (count = 0; environ[count]; count++)
			printf("%s\n", environ[count]);

		free(argv);
		return (1);
	}

	return (0);
}

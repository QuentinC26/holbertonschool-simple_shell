#include "shell.h"

/**
 * tokenize_line - Découpe une ligne en tokens (commande + args)
 * @line: ligne brute de l'utilisateur
 * Return: tableau de tokens (NULL-terminated)
 */
char **tokenize_line(char *line)
{
	char **tokens = NULL;
	char *token = NULL;
	int bufsize = 64, i = 0;

	tokens = malloc(sizeof(char *) * bufsize);
	if (!tokens)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \t\n");
	while (token != NULL)
	{
		tokens[i++] = token;

		if (i >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, sizeof(char *) * bufsize);
			if (!tokens)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, " \t\n");
	}
	tokens[i] = NULL;

	return (tokens);
}

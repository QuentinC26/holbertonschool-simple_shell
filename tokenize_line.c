#include "shell.h"

/**
 * tokenize_line - Tokenizes a line of input into an array of strings
 * @line: The line to tokenize
 *
 * Return: An array of strings (tokens), or NULL on failure
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

	token = strtok(line, " \t\r\n");
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
		token = strtok(NULL, " \t\r\n");
	}
	tokens[i] = NULL;

	return (tokens);
}

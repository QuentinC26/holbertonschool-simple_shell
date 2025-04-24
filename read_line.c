#include "shell.h"

/**
 * read_line - Lit la ligne entrée par l’utilisateur
 * Return: string (ligne), ou NULL si EOF
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	nread = getline(&line, &len, stdin);

	if (nread == -1)
	{
		free(line);
		return (NULL);
	}

	/* Supprime le \n de fin */
	if (line[nread - 1] == '\n')
		line[nread - 1] = '\0';

	return (line);
}

#include "shell.h"

/**
 * find_command_path - Finds the full path of a command
 * @command: The command to find
 *
 * Return: The full path of the command, or NULL if not found
 */
char *find_command_path(char *command)
{
	char *path, *path_copy, *dir, *full_path;
	struct stat st;

	if (stat(command, &st) == 0)
		return (strdup(command)); /* déjà un chemin absolu ou relatif valide */

	path = my_getenv("PATH");
	if (!path)
		return (NULL);

	path_copy = strdup(path);
	if (!path_copy)
		return (NULL);
	dir = strtok(path_copy, ":");

	while (dir)
	{
		full_path = malloc(strlen(dir) + strlen(command) + 2);
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}
		sprintf(full_path, "%s/%s", dir, command);

		if (stat(full_path, &st) == 0)
		{
			free(path_copy);
			return (full_path); /* trouvé */
		}

		free(full_path);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL); /* non trouvé */
}

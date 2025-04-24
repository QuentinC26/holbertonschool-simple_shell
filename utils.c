#include "shell.h"

/**
 * my_getenv - Récupère la valeur d'une variable d'environnement
 * @name: nom de la variable d'environnement
 * Return: valeur de la variable ou NULL si non trouvée
 */
char *my_getenv(const char *name)
{
	int i = 0;
	size_t len = strlen(name);

	while (environ[i])
	{
		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
			return (environ[i] + len + 1);
		i++;
	}

	return (NULL);
}

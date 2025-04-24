#include "shell.h"

/**
 * my_getenv - Get the value of an environment variable.
 * @name: The name of the environment variable.
 *
 * Return: The value of the environment variable, or NULL if not found.
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

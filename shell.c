#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

extern char **environ;

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    pid_t pid;

    while (1)
    {
        write(STDOUT_FILENO, "#cisfun$ ", 9);

        read = getline(&line, &len, stdin);
        if (read == -1) // Ctrl+D ou erreur
        {
            write(STDOUT_FILENO, "\n", 1);
            break;
        }

        // Supprimer le \n à la fin de la commande
        if (line[read - 1] == '\n')
            line[read - 1] = '\0';

        pid = fork();
        if (pid == -1)
        {
            perror("fork");
            continue;
        }

        if (pid == 0) // Processus fils
        {
            char *argv[2];
            argv[0] = line;
            argv[1] = NULL;

            if (execve(line, argv, environ) == -1)
            {
                perror("./shell");
                exit(EXIT_FAILURE);
            }
        }
        else // Processus parent
        {
            wait(NULL);
        }
    }

    free(line);
    return (0);
}

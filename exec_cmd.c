#include "shell.h"

/**
 * execute_cmd - execute a command in the child process
 * @line: command line for exectute
 * Return: void
 */

void execute_cmd(char *line)
{
	char **argv = tokenize_line(line);
	char *cmd_path;
	pid_t pid;

	if (!argv || !argv[0])
	{
		free(argv);
		return;
	}
	if (handle_builtin(argv))
		return;
	cmd_path = find_command_path(argv[0]);
	if (!cmd_path)
	{
		fprintf(stderr, "./shell: command not found: %s\n", argv[0]);
		free(argv);
		return;
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(argv);
		free(cmd_path);
		return;
	}
	if (pid == 0)
	{
		if (execve(cmd_path, argv, environ) == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
		free(cmd_path);
		free(argv);
	}
}

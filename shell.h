#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

void display_prompt(void);
char *read_line(void);
void execute_cmd(char *line);
char *_strdup(const char *str);
char **tokenize_line(char *line);
char *my_getenv(const char *name);
int handle_builtin(char **argv);
char *find_command_path(char *command);



#endif

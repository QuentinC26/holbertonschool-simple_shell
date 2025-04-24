#include "shell.h"

/**
 * display_prompt - Affiche le prompt
 */
void display_prompt(void)
{
	write(STDOUT_FILENO, "#cisfun$ ", 9);
}

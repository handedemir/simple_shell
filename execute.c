#include "main.h"

/**
 * exec - a function thats execute a shell program
 * @argv: var name to use
 * Return: void
 */
void exec(char **argv)
{
	char *cmd_in = NULL, *actual_cmd_in = NULL;

	if (argv && argv[0])
	{
		/* get the command */
		cmd_in = argv[0];

		/* generate the path to this command before passing it to execve */
		actual_cmd_in = locate_cmd(cmd_in);

		if (actual_cmd_in == NULL)
		{
			perror("command path not found");
			return;
		}

		/* execute the actual command with execve */
		if (execve(actual_cmd_in, argv, NULL) == -1)
		{
			perror("Error:");
			free(actual_cmd_in);
			return;
		}
		free(actual_cmd_in);
	}
}

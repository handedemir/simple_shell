#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include "shell.h"
/**
 * main - Entry point
 * @argc: element 1
 * @argv: element 2
 * @env_lp: element 3
 * Return: 0
 */
int main(int argc __attribute__((unused)),
		char *argv[] __attribute__((unused)), char *env_lp[])
{
	int dw;
	char **envv = env_lp;
	char *args[] = {"cat", "output.txt", NULL};

	/*Create a file descriptor to write to output.txt*/
	dw = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC,
S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

	if (dw == -1)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	/*Write environment variables to output.txt*/
	while (*envv != NULL)
	{
		char *current_envv = *envv;
		size_t length = strlen(current_envv);

		write(dw, current_envv, length);
		write(dw, "\n", 1);
		envv++;
	}

    /*Close the file descriptor*/
	close(dw);

	if (execve("/bin/cat", args, env_lp) == -1)

	/* Execute the cat command to display the contents of output.txt*/
	{
		perror("execve failed");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

/**
 * main - Entry point
 * Return: 0
 */

int main(int argc, char *argv[], char *env_lp[])
{
	/*Create a file descriptor to write to output.txt*/
	int dw = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC,
S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

	if (dw == -1)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	/*Retrieve environment variables*/
	char **envv = env_lp;
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

    /* Create arguments for the execve function*/
	char *args[] = {"cat", "output.txt", NULL};

	/* Execute the cat command to display the contents of output.txt*/
	execve("/bin/cat", args, env_lp);
	return (0);
}

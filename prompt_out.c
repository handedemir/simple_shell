#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

/**
 * print_prompt - here we are passing our prompt
 * @dg: parameter 1
 * @str: parameter 2
 * Return: 0
 */
void print_prompt(int dg, const char *str)
{
	write(dg, str, strlen(str));
}
/**
 * main - entry point of main program
 * Return: 0
 */

int main(void)
{
	char *comm = NULL;
	size_t comm_len = 0;
	ssize_t read_chars;
	int status;
	pid_t pid;


	while (1)
	{
		pid = fork();

		if (pid < 0)
		{
			perror("Fork failed");
			exit(EXIT_FAILURE);
		}else if(pid == 0)
		{
			
		print_prompt(STDOUT_FILENO, "$: ");
		fflush(stdout);

		read_chars = getline(&comm, &comm_len, stdin);

		if (read_chars == -1)
		{
			perror("Error reading command");
			continue;
		}
		comm[strcspn(comm, "\n")] = '\0';

			char *args[2];

			args[0] = comm;
			args[1] = NULL;

			execve(comm, args, NULL);

			perror("Error executing command");
			exit(EXIT_FAILURE);
		} else
		{
			waitpid(pid, &status, 0);
		}
	}
	free(comm);
	return (0);
}

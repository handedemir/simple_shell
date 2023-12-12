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
	int status;

	while (1)
	{
		print_prompt(STDOUT_FILENO, "$: ");
		fflush(stdout);

		ssize_t read = getline(&comm, &comm_len, stdin);

		if (read == -1)
		{
			perror("Error reading command");
			continue;
		}
		comm[strcspn(comm, "\n")] = '\0';
		pid_t pid = fork();

		if (pid < 0)
		{
			perror("Fork failed");
			exit(EXIT_FAILURE);
		} else if (pid == 0)
		{
			char *args[] = { comm, NULL };

			execve(comm, args, NULL);
			write(STDERR_FILENO, "Error: No such file or directory\n",
					strlen("Error: No such file or directory\n"));
			exit(EXIT_FAILURE);
		} else
		{
			waitpid(pid, &status, 0);
		}
	}
	free(comm);
	return (0);
}

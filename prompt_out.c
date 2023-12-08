#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

/**
 * custom_print - here we are passing our prompt
 * @fd: parameter 1
 * @str: parameter 2
 * Return: 0
 */
void custom_print(int fd, const char *str)
{
	write(fd, str, strlen(str));
}
/**
 * main - entry point of main program
 * Return: 0
 */
int main(void)
{
	char *command = NULL;
	size_t command_len = 0;
	int status;

	while (1)
	{
		custom_print(STDOUT_FILENO, "$:  ");
		fflush(stdout);

		ssize_t read = getline(&command, &command_len, stdin);

		if (read == -1)
		{
			perror("Error reading command");
			continue;
		}
		command[strcspn(command, "\n")] = '\0';
		pid_t pid = fork();

		if (pid < 0)
		{
			perror("Fork failed");
			exit(EXIT_FAILURE);
		} else if (pid == 0)
		{
			char *args[] = { command, NULL };

			execve(command, args, NULL);
			write(STDERR_FILENO, "Error: Command not found\n",
					strlen("Error: Command not found\n"));
			exit(EXIT_FAILURE);
		} else
		{
			waitpid(pid, &status, 0);
		}
	}
	free(command);
	return (0);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
/**
 * main - the entry point to start the program
 * Return: 0
 */

int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	int status;

	while (1)
	{
		printf("$:");
		fflush(stdout); /*Flush the output buffer to ensure prompt is displayed*/
		if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			perror("Error reading command");
			continue;
		}
		/*Remove trailing newline character*/
		command[strcspn(command, "\n")] = '\0';

		pid_t pid = fork();

		if (pid < 0)
		{
			perror("Fork failed");
			exit(EXIT_FAILURE);
		} else if (pid == 0)
		{ /*Child process*/
			/*Execute the command*/
			execlp(command, command, NULL);

			/*If execlp returns, it means the command was not found*/
			fprintf(stderr, "Error: Command not found\n");

			exit(EXIT_FAILURE);
		} else
		{ /*Parent process*/
			/*Wait for the child process to finish*/
			waitpid(pid, &status, 0);
		}
	}
	return (0);
}

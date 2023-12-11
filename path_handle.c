#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT_SIZE 1024

void display_prompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}

char *read_input()
{
	char *input = NULL;
	size_t len = 0;
	ssize_t read;

	display_prompt();
	read = getline(&input, &len, stdin);

	if (read == -1)
	{
		perror("getline");
		exit(EXIT_FAILURE);
	}

	input[strcspn(input, "\n")] = '\0';/*Remove newline character*/
	return (input);
}
void execute_command(char *input)
{
	char *token;
	char *path = getenv("PATH");
	char *path_copy = strdup(path);

	token = strtok(path_copy, ":");

	int command_found = 0;

	while (token != NULL)
	{
		size_t command_path_len = strlen(token) + strlen(input) + 2;
		char command_path[command_path_len];

		strcpy(command_path, token);
		strcat(command_path, "/");
		strcat(command_path, input);

		if (access(command_path, X_OK) == 0)
		{
			command_found = 1;
			execve(command_path, (char *[]){input, NULL}, NULL);
			perror("execve");
			break;
		}

		token = strtok(NULL, ":");
	}

	free(path_copy);

	if (!command_found)
	{
		write(STDOUT_FILENO, "Command not found\n", 18);
	}
}

int main(void)
{
	char *input;

	while (1)
	{
		input = read_input();
		execute_command(input);
		free(input);
	}
	return (0);
}

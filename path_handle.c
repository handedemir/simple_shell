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

	int command_found = 0;
	size_t input_len = strlen(input);

	token = strtok(path_copy, ":");

	while (token != NULL)
	{
		size_t command_path_len = strlen(token) + input_len + 2;
		char *command_path = (char *)malloc(command_path_len);

		if (command_path == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}

		strcpy(command_path, token);
		strcat(command_path, "/");
		strcat(command_path, input);

		if (access(command_path, X_OK) == 0)
		{
			char **args = (char **)malloc(sizeof(char *) * 2);

			command_found = 1;

			if (args == NULL)
			{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
			args[0] = input;
			args[1] = NULL;

			execve(command_path, args, NULL);
			perror("execve");
			free(args);
			free(command_path);
			break;
	}
		free(command_path);
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

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "shell.h"

#define MAX_INPUT_LENGTH 100
/**
 * main - the entry point
 * Return: 0
 */

int main(void)
{
	char *input_in = NULL;
	size_t length = 0;
	ssize_t read;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2); /*Display prompt*/
		read = getline(&input_in, &length, stdin); /*Read input*/

		if (read == -1)
		{
			perror("getline");
			free(input_in);
			exit(EXIT_FAILURE);
		}
		input_in[strcspn(input_in, "\n")] = '\0'; /*Remove newline character*/

		if (strcmp(input_in, "exit") == 0)
		{
			write(STDOUT_FILENO, "Exiting shell...\n", 17);
			free(input_in);
			exit(EXIT_SUCCESS);
		}
		/*If the command is not exit, you can add other commands here*/
		write(STDOUT_FILENO, "Command not found\n", 20);
	}
	return (0);
}

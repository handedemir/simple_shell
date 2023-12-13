#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ARGS 10
#define MAX_INPUT 1024
/**
 * main - the main function to start over
 * Return: 0
 */
int main(void)
{
	ssize_t byte_toread;
	char input_el[MAX_INPUT];
	char *args[MAX_ARGS + 1];
	int argc = 0;
	char *token = strtok(input_el, " ");

    /*Read the command line input*/
	write(STDOUT_FILENO, "Please Enter command: ", 22);
	byte_toread = read(STDIN_FILENO, input_el, MAX_INPUT);
	if (byte_toread == -1)
	{
		perror("Error reading input");
		exit(EXIT_FAILURE);
	}
	input_el[byte_toread - 1] = '\0'; /*Removing newline character*/

    /*Tokenize the input into arguments*/

	while (token != NULL && argc < MAX_ARGS)
	{
		args[argc++] = token;
		token = strtok(NULL, " ");
	}
	args[argc] = NULL; /*Set the last element to NULL for execve*/

    /*Execute the command*/
	if (argc > 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("Execution error");
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}

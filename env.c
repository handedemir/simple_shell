#include "main.h"

/**
 * print_envir - function is to print the environment
 * Return: when is successful 0 is returned
 * -1 is returned when error occurs
 * It is initailized by the use of 'environ' command
 */

int print_envir(void)
{
	char **envir_ptr = environ;

	while (*envir_ptr)
	{
		size_t length = 0;

		while ((*envir_ptr)[length])
			length++;

		write(STDOUT_FILENO, *envir_ptr, length);
		write(STDOUT_FILENO, "\n", 1);

		envir_ptr++;
	}

	return (0);
}

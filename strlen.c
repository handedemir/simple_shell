#include "main.h"

/**
 * _strlen - we are returning the length of the string
 * @str: string to use
 * Return: length to use
 */
int _strlen(char *str)
{
	int str_length = 0;

	while (*str != '\0')
	{
		str_length++;
		str++;
	}

	return (str_length);
}

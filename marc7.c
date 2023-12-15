#include "shell.h"

/**
 * bfree - frees a pointer and NULLs the address to the output
 * @ptr: address of the pointer to free the memory
 * Return: 1 if freed, otherwise 0 is used
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

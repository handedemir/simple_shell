#include "main.h"

/**
 * char *_strcpy - a function that copies the string pointers to use
 * @dest: copy to destination
 * @src: copy from source
 * Return: string to use
 */
char *_strcpy(char *dest, char *src)
{
	int k = 0;
	int z = 0;

	while (*(src + k) != '\0')
	{
		k++;
	}
	for ( ; z < k ; z++)
	{
		dest[z] = src[z];
	}
	dest[k] = '\0';
	return (dest);
}

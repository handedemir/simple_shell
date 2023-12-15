#include "main.h"
/**
 * _strcat - we are concatinating two strings
 * @dest: input value to use
 * @src: input value to use
 *
 * Return: void
 */
char *_strcat(char *dest, char *src)
{
	int k = 0;
	int l = 0;

	while (dest[k] != '\0')
	{
		k++;
	}

	while (src[l] != '\0')
	{
		dest[k] = src[l];
		k++;
		l++;
	}

	dest[k] = '\0';
	return (dest);
}

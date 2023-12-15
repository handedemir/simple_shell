#include "main.h"
/**
 * _strcmp - compare string values to use
 * @str1: input value to use
 * @str2: input value to use
 *
 * Return: str[j] - str2[j]
 */
int _strcmp(char *str1, char *str2)
{
	int k;

	k = 0;
	while (str1[k] != '\0' && str2[k] != '\0')
	{
		if (str1[k] != str2[k])
		{
			return (str1[k] - str2[k]);
		}
		k++;
	}
	return (0);
}

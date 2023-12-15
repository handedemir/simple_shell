#include "marc8.h"

/**
 * _strlen - returns the length of a string
 * @mar: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *mar)
{
	int i = 0;

	if (!mar)
		return (0);

	while (*mar++)
		i++;
	return (i);
}

/**
 * _strcmp - performs lexicogarphic comparison of two strangs.
 * @s1: the first strang
 * @s2: the second strang
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - checks if needle starts with haystck
 * @haystck: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystck or NULL
 */
char *starts_with(const char *haystck, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystck++)
			return (NULL);
	return ((char *)haystck);
}

/**
 * _strcat - concatenates two strings
 * @des: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *des, char *src)
{
	char *ret = des;

	while (*des)
		des++;
	while (*src)
		*des++ = *src++;
	*des = *src;
	return (ret);
}

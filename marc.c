#include "marc8.h"

/**
<<<<<<< HEAD
 * interactive - returns true if shell is interactive mode
 * @dat: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
=======
 * interactive - returns true if shell is correct
 * @info: this is the struct of the address
 * Return: 1
>>>>>>> 0322a0f009417584704cafef0138ec3b81b77a6d
 */
int interactive(info_t *dat)
{
	return (isatty(STDIN_FILENO) && dat->readfd <= 2);
}

/**
<<<<<<< HEAD
 * is_delim - checks if character is a delimeter
 * @c: the char to check
 * @delmiter: the delimeter string
 * Return: 1 if true, 0 if false
=======
 * is_delim - delimiter is to be checked
 * @c: the parameter c
 * @delim: delimeter that we are going to use
 * Return: 1 for positive, or otherwise
>>>>>>> 0322a0f009417584704cafef0138ec3b81b77a6d
 */
int is_delim(char c, char *delmiter)
{
	while (*delmiter)
		if (*delmiter++ == c)
			return (1);
	return (0);
}

/**
 *_isalpha - function is checking alphabets
 *@c: The character that are used
 *Return: for the alphabets we return 1, 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - we are converting a string to an integer
 *@s: we are checking the strings in here
 *Return: 0 no number found, or otherwise
 */

int _atoi(char *s)
{
	int k, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (k = 0;  s[k] != '\0' && flag != 2; k++)
	{
		if (s[k] == '-')
			sign *= -1;

		if (s[k] >= '0' && s[k] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[k] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

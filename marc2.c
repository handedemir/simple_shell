#include "marc8.h"

/**
 *_eputs - prints an input string
 * @strx: the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *strx)
{
	int k = 0;

	if (!strx)
		return;
	while (strx[i] != '\0')
	{
		_eputchar(strx[i]);
		i++;
	}
}

/**
 * _eputchar - cis going to be written  to stderr
 * @c: parameter to print character
 * Return: 1 is returned
 * On error, -1 is returned for the error cases
 */
int _eputchar(char c)
{
	static int k;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || k >= WRITE_BUF_SIZE)
	{
		write(2, buf, k);
		k = 0;
	}
	if (c != BUF_FLUSH)
		buf[k++] = c;
	return (1);
}

/**
 * _putfd - character c have the relationship with fd
 * @c: c is the character to be printed
 * @fd: The filedescriptor that we will write from
 * Return: when is success 1 is printed
 * On error, -1 for error case
 */
int _putfd(char c, int fd)
{
	static int k;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || k >= WRITE_BUF_SIZE)
	{
		write(fd, buf, k);
	k = 0;
	}
	if (c != BUF_FLUSH)
		buf[k++] = c;
	return (1);
}

/**
 *_putsfd - prints an input string
 * @strx: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *strx, int fd)
{
	int k = 0;

	if (!strx)
		return (0);
	while (*strx)
	{
<<<<<<< HEAD
		i += _putfd(*strx++, fd);
=======
		k += _putfd(*str++, fd);
>>>>>>> 0322a0f009417584704cafef0138ec3b81b77a6d
	}
	return (k);
}

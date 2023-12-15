#include "marc8.h"

/**
 * _myenv - prints the current env to the output
 * @dat: Structure containing potential arguments
 * Return: Always 0 is used
 */
int _myenv(info_t *dat)
{
	print_list_str(dat->envi);
	return (0);
}

/**
 * _getenv - gets the value of an environ variable to use
 * @dat: Structure containing potential arguments to use
 * @nam: envi var nam
 * Return: the value at the output
 */
char *_getenv(info_t *dat, const char *nam)
{
	list_t *inter = dat->envi;
	char *p;

	while (inter)
	{
		p = starts_with(inter->str, nam);
		if (p && *p)
			return (p);
		inter = inter->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initialize a new environment variable to use
 * @dat: Structure containing potential arguments to use
 *  Return: Always 0 is used
 */
int _mysetenv(info_t *dat)
{
	if (dat->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(dat, dat->argv[1], dat->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove an environment variable to use
 * @dat: Structure containing potential arguments.
 *  Return: Always 0 is used
 */
int _myunsetenv(info_t *dat)
{
	int v;

	if (dat->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (v = 1; v <= dat->argc; v++)
		_unsetenv(dat, dat->argv[v]);

	return (0);
}

/**
 * populate_env_list - populates env linked list to the public
 * @dat: Structure containing potential arguments to use to the output
 * Return: Always 0 is used
 */
int populate_env_list(info_t *dat)
{
	list_t *inter = NULL;
	size_t v;

	for (v = 0; environ[v]; v++)
		add_node_end(&inter, environ[v], 0);
	dat->environ = inter;
	return (0);
}

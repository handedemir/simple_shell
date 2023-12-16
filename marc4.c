#include "marc8.h"

/**
 * get_environ - returns the string array copy of our environ to use
 * @dat: Structure containing potential arguments. Used to maintain
 *          constant function prototype to use
 * Return: Always 0 to be used
 */
char **get_environ(info_t *dat)
{
	if (!dat->environ || dat->env_changed)
	{
		dat->environ = list_to_strings(dat->envi);
		dat->env_changed = 0;
	}

	return (dat->environ);
}

/**
 * _unsetenv - function that can Remove env
 * @dat: Structure containing potential arguments to use
 * @var: the string envi var property to use
 * Return: 0 to be returned
 */
int _unsetenv(info_t *dat, char *var)
{
	list_t *node = info->env;
	size_t k = 0;
	char *d;

/**
 * _unsetenv - Remove an environment variable to use
 * @dat: Structure containing potential arguments to use
 * @var: the variable
 * Return: 0
 *
 */
int _unsetenv(info_t *dat, char *var)
{
	list_t *node = dat->envi;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		d = starts_with(node->str, var);
		if (d && *d == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), i);
			k = 0;
			node = info->env;

			dat->env_changed = delete_node_at_index(&(dat->envi), i);
			i = 0;
			node = dat->envi;

			continue;
		}
		node = node->next;
		k++;
	}
	return (dat->env_changed);
}

/**
 * _setenv - Initialize a new environment variable or set environment as well
 * @var: the string env var property to be used
 * @value: the string env var value that are needed to be used
 *  Return: Always 0 is returned
 */
int _setenv(info_t *dat, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *d;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = dat->envi;
	while (node)
	{
		d = starts_with(node->str, var);
		if (d && *d == '=')
		{
			free(node->str);
			node->str = buf;
			dat->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(dat->envi), buf, 0);
	free(buf);
	dat->env_changed = 1;
	return (0);
}

#include "marc8.h"

/**
 * get_environ - returns the string array copy of our environ
 * @dat: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
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
 * _unsetenv - Remove an environment variable
 * @dat: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: 1 on delete, 0 otherwise
 * @var: the string envi var property
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
			continue;
		}
		node = node->next;
		k++;
	}
	return (dat->env_changed);
}

/**
 * _setenv - Initialize a new environment variable or set environment as well
 * @info: Structure containing potential arguments to be used
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

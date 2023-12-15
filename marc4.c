#include "marc8.h"

/**
<<<<<<< HEAD
 * get_environ - copy code of our environement
 * @info: Structure containing potential arguments
 * Return: Always 0 when is successfull
=======
 * get_environ - returns the string array copy of our environ
 * @dat: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
>>>>>>> 5217b126e9e2c9e9c8efe68f57e773e162ef8a6a
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
<<<<<<< HEAD
 * _unsetenv - function that can Remove an environment variable
 * @info: Structure containing potential arguments
 *  Return: 1 on delete, 0 otherwise
 * @var: the string env var property to be used
=======
 * _unsetenv - Remove an environment variable
 * @dat: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: 1 on delete, 0 otherwise
 * @var: the string envi var property
>>>>>>> 5217b126e9e2c9e9c8efe68f57e773e162ef8a6a
 */
int _unsetenv(info_t *dat, char *var)
{
<<<<<<< HEAD
	list_t *node = info->env;
	size_t k = 0;
	char *d;
=======
	list_t *node = dat->envi;
	size_t i = 0;
	char *p;
>>>>>>> 5217b126e9e2c9e9c8efe68f57e773e162ef8a6a

	if (!node || !var)
		return (0);

	while (node)
	{
		d = starts_with(node->str, var);
		if (d && *d == '=')
		{
<<<<<<< HEAD
			info->env_changed = delete_node_at_index(&(info->env), i);
			k = 0;
			node = info->env;
=======
			dat->env_changed = delete_node_at_index(&(dat->envi), i);
			i = 0;
			node = dat->envi;
>>>>>>> 5217b126e9e2c9e9c8efe68f57e773e162ef8a6a
			continue;
		}
		node = node->next;
		k++;
	}
	return (dat->env_changed);
}

/**
<<<<<<< HEAD
 * _setenv - Initialize a new environment variable or set environment as well
 * @info: Structure containing potential arguments to be used
 * @var: the string env var property to be used
 * @value: the string env var value that are needed to be used
 *  Return: Always 0 is returned
=======
 * _setenv - Initialize a new environment variable,
 *             or modify an existing one
 * @dat: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @var: the string envi var property
 * @value: the string envi var value
 *  Return: Always 0
>>>>>>> 5217b126e9e2c9e9c8efe68f57e773e162ef8a6a
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

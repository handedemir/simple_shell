#include "shell.h"

/**
 * get_environ - copy code of our environement
 * @info: Structure containing potential arguments
 * Return: Always 0 when is successfull
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _unsetenv - function that can Remove an environment variable
 * @info: Structure containing potential arguments
 *  Return: 1 on delete, 0 otherwise
 * @var: the string env var property to be used
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t k = 0;
	char *d;

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
	return (info->env_changed);
}

/**
 * _setenv - Initialize a new environment variable or set environment as well
 * @info: Structure containing potential arguments to be used
 * @var: the string env var property to be used
 * @value: the string env var value that are needed to be used
 *  Return: Always 0 is returned
 */
int _setenv(info_t *info, char *var, char *value)
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
	node = info->env;
	while (node)
	{
		d = starts_with(node->str, var);
		if (d && *d == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}

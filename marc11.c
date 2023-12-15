#include "shell.h"

/**
 * _myenv - prints the current env to the output
 * @info: Structure containing potential arguments
 * Return: Always 0 is used
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - gets the value of an environ variable to use
 * @info: Structure containing potential arguments to use
 * @name: env var name
 * Return: the value at the output
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initialize a new environment variable to use
 * @info: Structure containing potential arguments to use
 *  Return: Always 0 is used
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove an environment variable to use
 * @info: Structure containing potential arguments.
 *  Return: Always 0 is used
 */
int _myunsetenv(info_t *info)
{
	int v;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (v = 1; v <= info->argc; v++)
		_unsetenv(info, info->argv[v]);

	return (0);
}

/**
 * populate_env_list - populates env linked list to the public
 * @info: Structure containing potential arguments to use to the output
 * Return: Always 0 is used
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t v;

	for (v = 0; environ[v]; v++)
		add_node_end(&node, environ[v], 0);
	info->env = node;
	return (0);
}

#include "shell.h"

/**
 * _myhistory - displays the history list
 * @info: Structure containing potential arguments used
 *  Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - alias is set
 * @info: strcut is used as parameter
 * @str: alias is used as the string
 * Return: return 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *d, c;
	int ret;

	d = _strchr(str, '=');
	if (!d)
		return (1);
	c = *d;
	*d = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*d = c;
	return (ret);
}

/**
 * set_alias - alias is set to string
 * @info: struct is used as a parameter
 * @str: alias is used as struct
 * Return: 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *d;

	d = _strchr(str, '=');
	if (!d)
		return (1);
	if (!*++d)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias
 * @node: the alias node to be used
 * Return: 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *d = NULL, *a = NULL;

	if (node)
	{
		d = _strchr(node->str, '=');
		for (a = node->str; a <= d; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(d + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics (man alias) is used
 * @info: Structure containing potential arguments to be used
 *  Return: Always 0 to be returned
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *d = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		d = _strchr(info->argv[i], '=');
		if (d)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}

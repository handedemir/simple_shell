#include "marc8.h"

/**
<<<<<<< HEAD
 * _myhistory - displays the history list
 * @info: Structure containing potential arguments used
=======
 * _myhistory - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @dat: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
>>>>>>> 5217b126e9e2c9e9c8efe68f57e773e162ef8a6a
 *  Return: Always 0
 */
int _myhistory(info_t *dat)
{
	print_list(dat->history);
	return (0);
}

/**
<<<<<<< HEAD
 * unset_alias - alias is set
 * @info: strcut is used as parameter
 * @str: alias is used as the string
 * Return: return 0 on success, 1 on error
=======
 * unset_alias - sets alias to string
 * @dat: parameter struct
 * @strx: the string alias
 *
 * Return: Always 0 on success, 1 on error
>>>>>>> 5217b126e9e2c9e9c8efe68f57e773e162ef8a6a
 */
int unset_alias(info_t *dat, char *strx)
{
	char *d, c;
	int ret;

<<<<<<< HEAD
	d = _strchr(str, '=');
	if (!d)
		return (1);
	c = *d;
	*d = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*d = c;
=======
	p = _strchr(strx, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(dat->alias),
		get_node_index(dat->alias, node_starts_with(dat->alias, strx, -1)));
	*p = c;
>>>>>>> 5217b126e9e2c9e9c8efe68f57e773e162ef8a6a
	return (ret);
}

/**
<<<<<<< HEAD
 * set_alias - alias is set to string
 * @info: struct is used as a parameter
 * @str: alias is used as struct
 * Return: 0 on success, 1 on error
=======
 * set_alias - sets alias to string
 * @dat: parameter struct
 * @strx: the string alias
 *
 * Return: Always 0 on success, 1 on error
>>>>>>> 5217b126e9e2c9e9c8efe68f57e773e162ef8a6a
 */
int set_alias(info_t *dat, char *strx)
{
	char *d;

<<<<<<< HEAD
	d = _strchr(str, '=');
	if (!d)
		return (1);
	if (!*++d)
		return (unset_alias(info, str));
=======
	p = _strchr(strx, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(dat, strx));
>>>>>>> 5217b126e9e2c9e9c8efe68f57e773e162ef8a6a

	unset_alias(dat, strx);
	return (add_node_end(&(dat->alias), strx, 0) == NULL);
}

/**
<<<<<<< HEAD
 * print_alias - prints an alias
 * @node: the alias node to be used
 * Return: 0 on success, 1 on error
=======
 * print_alias - prints an alias string
 * @inter: the alias inter
 *
 * Return: Always 0 on success, 1 on error
>>>>>>> 5217b126e9e2c9e9c8efe68f57e773e162ef8a6a
 */
int print_alias(list_t *inter)
{
	char *d = NULL, *a = NULL;

	if (inter)
	{
<<<<<<< HEAD
		d = _strchr(node->str, '=');
		for (a = node->str; a <= d; a++)
=======
		p = _strchr(inter->str, '=');
		for (a = inter->str; a <= p; a++)
>>>>>>> 5217b126e9e2c9e9c8efe68f57e773e162ef8a6a
			_putchar(*a);
		_putchar('\'');
		_puts(d + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
<<<<<<< HEAD
 * _myalias - mimics (man alias) is used
 * @info: Structure containing potential arguments to be used
 *  Return: Always 0 to be returned
=======
 * _myalias - mimics the alias builtin (man alias)
 * @dat: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
>>>>>>> 5217b126e9e2c9e9c8efe68f57e773e162ef8a6a
 */
int _myalias(info_t *dat)
{
	int i = 0;
<<<<<<< HEAD
	char *d = NULL;
	list_t *node = NULL;
=======
	char *p = NULL;
	list_t *inter = NULL;
>>>>>>> 5217b126e9e2c9e9c8efe68f57e773e162ef8a6a

	if (dat->argc == 1)
	{
		inter = dat->alias;
		while (inter)
		{
			print_alias(inter);
			inter = inter->next;
		}
		return (0);
	}
	for (i = 1; dat->argv[i]; i++)
	{
<<<<<<< HEAD
		d = _strchr(info->argv[i], '=');
		if (d)
			set_alias(info, info->argv[i]);
=======
		p = _strchr(dat->argv[i], '=');
		if (p)
			set_alias(dat, dat->argv[i]);
>>>>>>> 5217b126e9e2c9e9c8efe68f57e773e162ef8a6a
		else
			print_alias(node_starts_with(dat->alias, dat->argv[i], '='));
	}

	return (0);
}

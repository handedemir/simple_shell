#include "marc8.h"

/**
 * _myhistory - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @dat: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myhistory(info_t *dat)
{
	print_list(dat->history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @dat: parameter struct
 * @strx: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *dat, char *strx)
{
	char *p, c;
	int ret;

	p = _strchr(strx, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(dat->alias),
		get_node_index(dat->alias, node_starts_with(dat->alias, strx, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - sets alias to string
 * @dat: parameter struct
 * @strx: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *dat, char *strx)
{
	char *p;

	p = _strchr(strx, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(dat, strx));

	unset_alias(dat, strx);
	return (add_node_end(&(dat->alias), strx, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @inter: the alias inter
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *inter)
{
	char *p = NULL, *a = NULL;

	if (inter)
	{
		p = _strchr(inter->str, '=');
		for (a = inter->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias builtin (man alias)
 * @dat: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myalias(info_t *dat)
{
	int i = 0;
	char *p = NULL;
	list_t *inter = NULL;

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
		p = _strchr(dat->argv[i], '=');
		if (p)
			set_alias(dat, dat->argv[i]);
		else
			print_alias(node_starts_with(dat->alias, dat->argv[i], '='));
	}

	return (0);
}

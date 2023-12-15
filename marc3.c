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
>>>>>>> 166f5cbd13679e232f4a62e884a89b75e92bfc48
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
>>>>>>> 166f5cbd13679e232f4a62e884a89b75e92bfc48
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

<<<<<<< HEAD
/*
=======
/**
<<<<<<< HEAD
>>>>>>> 166f5cbd13679e232f4a62e884a89b75e92bfc48
 * set_alias - sets alias to string
 * @dat: parameter struct
 * @strx: the string alias
 *
 * Return: Always 0 on success, 1 on error
<<<<<<< HEAD
=======
=======
 * set_alias - alias is set to string
 * @info: struct is used as a parameter
 * @str: alias is used as struct
 * Return: 0 on success, 1 on error
>>>>>>> 0322a0f009417584704cafef0138ec3b81b77a6d
>>>>>>> 166f5cbd13679e232f4a62e884a89b75e92bfc48
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
=======
<<<<<<< HEAD
>>>>>>> 166f5cbd13679e232f4a62e884a89b75e92bfc48
	p = _strchr(strx, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(dat, strx));
<<<<<<< HEAD
=======
=======
	d = _strchr(str, '=');
	if (!d)
		return (1);
	if (!*++d)
		return (unset_alias(info, str));
>>>>>>> 0322a0f009417584704cafef0138ec3b81b77a6d
>>>>>>> 166f5cbd13679e232f4a62e884a89b75e92bfc48

	unset_alias(dat, strx);
	return (add_node_end(&(dat->alias), strx, 0) == NULL);
}

/**
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 166f5cbd13679e232f4a62e884a89b75e92bfc48
 * print_alias - prints an alias string
 * @inter: the alias inter
 *
 * Return: Always 0 on success, 1 on error
<<<<<<< HEAD
=======
=======
 * print_alias - prints an alias
 * @node: the alias node to be used
 * Return: 0 on success, 1 on error
>>>>>>> 0322a0f009417584704cafef0138ec3b81b77a6d
>>>>>>> 166f5cbd13679e232f4a62e884a89b75e92bfc48
 */
int print_alias(list_t *inter)
{
	char *d = NULL, *a = NULL;

	if (inter)
	{
<<<<<<< HEAD
		d = _strchr(node->str, '=');
		for (a = node->str; a <= d; a++)

		p = _strchr(inter->str, '=');
		for (a = inter->str; a <= p; a++)
=======
<<<<<<< HEAD
		p = _strchr(inter->str, '=');
		for (a = inter->str; a <= p; a++)
=======
		d = _strchr(node->str, '=');
		for (a = node->str; a <= d; a++)
>>>>>>> 0322a0f009417584704cafef0138ec3b81b77a6d
>>>>>>> 166f5cbd13679e232f4a62e884a89b75e92bfc48
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
=======
<<<<<<< HEAD
>>>>>>> 166f5cbd13679e232f4a62e884a89b75e92bfc48
 * _myalias - mimics the alias builtin (man alias)
 * @dat: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
<<<<<<< HEAD
=======
=======
 * _myalias - mimics (man alias) is used
 * @info: Structure containing potential arguments to be used
 *  Return: Always 0 to be returned
>>>>>>> 0322a0f009417584704cafef0138ec3b81b77a6d
>>>>>>> 166f5cbd13679e232f4a62e884a89b75e92bfc48
 */
int _myalias(info_t *dat)
{
	int i = 0;
<<<<<<< HEAD
	char *d = NULL;
	list_t *node = NULL;

	char *p = NULL;
	list_t *inter = NULL;
=======
<<<<<<< HEAD
	char *p = NULL;
	list_t *inter = NULL;
=======
	char *d = NULL;
	list_t *node = NULL;
>>>>>>> 0322a0f009417584704cafef0138ec3b81b77a6d
>>>>>>> 166f5cbd13679e232f4a62e884a89b75e92bfc48

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

		p = _strchr(dat->argv[i], '=');
		if (p)
			set_alias(dat, dat->argv[i]);
=======
<<<<<<< HEAD
		p = _strchr(dat->argv[i], '=');
		if (p)
			set_alias(dat, dat->argv[i]);
=======
		d = _strchr(info->argv[i], '=');
		if (d)
			set_alias(info, info->argv[i]);
>>>>>>> 0322a0f009417584704cafef0138ec3b81b77a6d
>>>>>>> 166f5cbd13679e232f4a62e884a89b75e92bfc48
		else
			print_alias(node_starts_with(dat->alias, dat->argv[i], '='));
	}

	return (0);
}

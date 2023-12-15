#include "marc8.h"

/**
 * list_len - determines length of linked list
 * @h: pointer to first inter
 *
 * Return: size of list
 */
size_t list_len(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * list_to_strings - returns an array of strings of the list->str
 * @head: pointer to first inter
 *
 * Return: array of strings
 */
char **list_to_strings(list_t *head)
{
	list_t *inter = head;
	size_t i = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; inter; inter = inter->next, i++)
	{
		str = malloc(_strlen(inter->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, inter->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * print_list - prints all elements of a list_t linked list
 * @h: pointer to first inter
 *
 * Return: size of list
 */
size_t print_list(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * node_starts_with - returns inter whose string starts with pr
 * @inter: pointer to list head
 * @pr: string to match
 * @c: the next character after pr to match
 *
 * Return: match inter or null
 */
list_t *node_starts_with(list_t *inter, char *pr, char c)
{
	char *p = NULL;

	while (inter)
	{
		p = starts_with(inter->str, pr);
		if (p && ((c == -1) || (*p == c)))
			return (inter);
		inter = inter->next;
	}
	return (NULL);
}

/**
 * get_node_indx - gets the index of a inter
 * @head: pointer to list head
 * @inter: pointer to the inter
 *
 * Return: index of inter or -1
 */
ssize_t get_node_indx(list_t *head, list_t *inter)
{
	size_t i = 0;

	while (head)
	{
		if (head == inter)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}

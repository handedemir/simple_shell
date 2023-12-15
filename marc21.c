#include "marc8.h"

/**
 * is_chain - test if current char in buffer is a chain delimeter
 * @dat: the parameter struct
 * @buffr: the char buffer
 * @p: address of current position in buffr
 *
 * Return: 1 if chain delimeter, 0 otherwise
 */
int is_chain(info_t *dat, char *buffr, size_t *p)
{
	size_t j = *p;

	if (buffr[j] == '|' && buffr[j + 1] == '|')
	{
		buffr[j] = 0;
		j++;
		dat->cmad_buffr_typ = CMD_OR;
	}
	else if (buffr[j] == '&' && buffr[j + 1] == '&')
	{
		buffr[j] = 0;
		j++;
		dat->cmad_buffr_typ = CMD_AND;
	}
	else if (buffr[j] == ';') /* found end of this command */
	{
		buffr[j] = 0; /* replace semicolon with null */
		dat->cmad_buffr_typ = CMD_CHAIN;
	}
	else
		return (0);
	*p = j;
	return (1);
}

/**
 * check_chain - checks we should continue chaining based on last status
 * @dat: the parameter struct
 * @buffr: the char buffer
 * @p: address of current position in buffr
 * @i: starting position in buffr
 * @len: length of buffr
 *
 * Return: Void
 */
void check_chain(info_t *dat, char *buffr, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (dat->cmad_buffr_typ == CMD_AND)
	{
		if (dat->status)
		{
			buffr[i] = 0;
			j = len;
		}
	}
	if (dat->cmad_buffr_typ == CMD_OR)
	{
		if (!dat->status)
		{
			buffr[i] = 0;
			j = len;
		}
	}

	*p = j;
}

/**
 * replace_alias - replaces an aliases in the tokenized string
 * @dat: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_alias(info_t *dat)
{
	int i;
	list_t *inter;
	char *p;

	for (i = 0; i < 10; i++)
	{
		inter = node_starts_with(dat->alis, dat->argv[0], '=');
		if (!inter)
			return (0);
		free(dat->argv[0]);
		p = _strchr(inter->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		dat->argv[0] = p;
	}
	return (1);
}

/**
 * replace_vars - replaces vars in the tokenized string
 * @dat: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_vars(info_t *dat)
{
	int i = 0;
	list_t *inter;

	for (i = 0; dat->argv[i]; i++)
	{
		if (dat->argv[i][0] != '$' || !dat->argv[i][1])
			continue;

		if (!_strcmp(dat->argv[i], "$?"))
		{
			replace_string(&(dat->argv[i]),
				_strdup(convert_number(dat->status, 10, 0)));
			continue;
		}
		if (!_strcmp(dat->argv[i], "$$"))
		{
			replace_string(&(dat->argv[i]),
				_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		inter = node_starts_with(dat->envi, &dat->argv[i][1], '=');
		if (inter)
		{
			replace_string(&(dat->argv[i]),
				_strdup(_strchr(inter->str, '=') + 1));
			continue;
		}
		replace_string(&dat->argv[i], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - replaces string
 * @old: address of old string
 * @new: new string
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}

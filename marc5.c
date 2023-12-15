#include "marc8.h"

/**
<<<<<<< HEAD
 * input_buf - commands for buffers
 * @info: parameter struct to use
 * @buf: buffer represents as an address
 * @len: address of length of variables
=======
 * input_buf - buffers chained commands
 * @dat: parameter struct
 * @buffr: address of buffer
 * @len: address of len var
>>>>>>> 5217b126e9e2c9e9c8efe68f57e773e162ef8a6a
 *
 * Return: bytes read to be used
 */
ssize_t input_buf(info_t *dat, char **buffr, size_t *len)
{
	ssize_t u = 0;
	size_t len_p = 0;

	if (!*len) /* if nothing left in the buffer, fill it */
	{
		/*bfree((void **)dat->cmd_buf);*/
		free(*buffr);
		*buffr = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
<<<<<<< HEAD
		u = getline(buf, &len_p, stdin);
#else
		u = _getline(info, buf, &len_p);
=======
		r = getline(buffr, &len_p, stdin);
#else
		r = _getline(dat, buffr, &len_p);
>>>>>>> 5217b126e9e2c9e9c8efe68f57e773e162ef8a6a
#endif
		if (u > 0)
		{
<<<<<<< HEAD
			if ((*buf)[u - 1] == '\n')
			{
				(*buf)[u - 1] = '\0'; /* remove trailing newline */
				u--;
=======
			if ((*buffr)[r - 1] == '\n')
			{
				(*buffr)[r - 1] = '\0'; /* remove trailing newline */
				r--;
>>>>>>> 5217b126e9e2c9e9c8efe68f57e773e162ef8a6a
			}
			dat->linecount_flag = 1;
			remove_comments(*buffr);
			build_history_list(dat, *buf, dat->histcount++);
			/* if (_strchr(*buf, ';')) is this a command chain? */
			{
<<<<<<< HEAD
				*len = u;
				info->cmd_buf = buf;
=======
				*len = r;
				dat->cmad_buffr = buffr;
>>>>>>> 5217b126e9e2c9e9c8efe68f57e773e162ef8a6a
			}
		}
	}
	return (u);
}

/**
<<<<<<< HEAD
 * get_input - gets a line and use it
 * @info: struct is used as parameter
 * Return: bytes read to use
=======
 * get_input - gets a line minus the newline
 * @dat: parameter struct
 *
 * Return: bytes read
>>>>>>> 5217b126e9e2c9e9c8efe68f57e773e162ef8a6a
 */
ssize_t get_input(info_t *dat)
{
	static char *buffr; /* the ';' command chain buffer */
	static size_t i, j, len;
<<<<<<< HEAD
	ssize_t u = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	u = input_buf(info, &buf, &len);
	if (u == -1) /* EOF */
=======
	ssize_t r = 0;
	char **buf_p = &(dat->arg), *p;

	_putchar(BUF_FLUSH);
	r = input_buf(dat, &buffr, &len);
	if (r == -1) /* EOF */
>>>>>>> 5217b126e9e2c9e9c8efe68f57e773e162ef8a6a
		return (-1);
	if (len)	/* we have commands left in the chain buffer */
	{
		j = i; /* init new iterator to current buf position */
		p = buffr + i; /* get pointer for return */

		check_chain(dat, buffr, &j, i, len);
		while (j < len) /* iterate to semicolon or end */
		{
			if (is_chain(dat, buffr, &j))
				break;
			j++;
		}

		i = j + 1; /* increment past nulled ';'' */
		if (i >= len) /* reached end of buffer? */
		{
			i = len = 0; /* reset position and length */
			dat->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p; /* pass back pointer to current command position */
		return (_strlen(p)); /* return length of current command */
	}

<<<<<<< HEAD
	*buf_p = buf; /* else not a chain, pass back buffer from _getline() */
	return (u); /* return length of buffer from _getline() */
}

/**
 * read_buf - reads a buffer to store values
 * @info: parameter struct to use
 * @buf: buffer to save
 * @i: size represent
 * Return: r is the return
=======
	*buf_p = buffr; /* else not a chain, pass back buffer from _getline() */
	return (r); /* return length of buffer from _getline() */
}

/**
 * read_buf - reads a buffer
 * @dat: parameter struct
 * @buffr: buffer
 * @i: size
 *
 * Return: r
>>>>>>> 5217b126e9e2c9e9c8efe68f57e773e162ef8a6a
 */
ssize_t read_buf(info_t *dat, char *buffr, size_t *i)
{
	ssize_t u = 0;

	if (*i)
		return (0);
<<<<<<< HEAD
	r = read(info->readfd, buf, READ_BUF_SIZE);
	if (u >= 0)
		*i = u;
	return (u);
}

/**
 * _getline - gets the next line of input
 * @info: parameter struct with info to use
 * @ptr: address of pointer to buffer to use
 * @length: size of pointers
 * Return: u to use
=======
	r = read(dat->readfd, buffr, READ_BUF_SIZE);
	if (r >= 0)
		*i = r;
	return (r);
}

/**
 * _getline - gets the next line of input from STDIN
 * @dat: parameter struct
 * @potr: address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated potr buffer if not NULL
 *
 * Return: s
>>>>>>> 5217b126e9e2c9e9c8efe68f57e773e162ef8a6a
 */
int _getline(info_t *dat, char **potr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t i, length;
	size_t k;
	ssize_t u = 0, u = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *potr;
	if (p && length)
<<<<<<< HEAD
		u = *length;
	if (i == len)
		i = len = 0;

	r = read_buf(info, buf, &len);
	if (u == -1 || (u == 0 && len == 0))
=======
		s = *length;
	if (i == length)
		i = length = 0;

	r = read_buf(dat, buffr, &len);
	if (r == -1 || (r == 0 && len == 0))
>>>>>>> 5217b126e9e2c9e9c8efe68f57e773e162ef8a6a
		return (-1);

	c = _strchr(buf + i, '\n');
	k = c ? 1 + (unsigned int)(c - buffr) : len;
	new_p = _realloc(p, s, s ? s + k : k + 1);
	if (!new_p) /* MALLOC FAILURE! */
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(new_p, buf + i, k - i);
	else
		_strncpy(new_p, buf + i, k - i + 1);

	s += k - i;
	i = k;
	p = new_p;

	if (length)
		*length = s;
	*potr = p;
	return (s);
}

/**
 * sigintHandler - blocks ctrl-C to use
 * @sig_num: the signal number to use
 * Return: void output
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}

#include "shell.h"

/**
 *remove_comments - removes comments from a string in function.
 *@ptr: arg 1.
 *@global: arg 2.
 *@fd: arg 3.
 *Return: string.
 */
char *remove_comments(char *ptr, global_t *global, int fd)
{
	int len = 0, k = 0, p;
	char    *str;

	if (!ptr)
	{
		global->cmd = NULL;
		if (isatty(fd))
			write(1, "\n", 1);
		p = global->exit_code;
		free_all(global);
		exit(p);
	}
	while (ptr[len] && ptr[len] != '\n')
	{
		if (ptr[len] == '#')
			if (ptr + len == ptr || ptr[len - 1] == ' ' || ptr[len - 1] == '\t')
				break;
		len++;
	}
	str = malloc(len + 1);
	while (ptr[k] && ptr[k] != '\n')
	{
		if (ptr[k] == '#')
			if (ptr + k == ptr || ptr[k - 1] == ' ' || ptr[k - 1] == '\t')
				break;
		str[k] = ptr[k];
		k++;
	}
	str[k] = '\0';
	free(ptr);
	return (str);
}

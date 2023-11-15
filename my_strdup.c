#include "shell.h"

/**
 * _strdup - function duplicates a string.
 * @str: string to be duplicated.
 * Return: a pointer to a new string.
 */
char *_strdup(const char *str)
{
	char *dupstr
	int len;
	int i;

	len = 0;
	i = -1;
	while (str[len])
		len++;
	dupstr = malloc(sizeof(char) * (len + 1));
	if (!dupstr)
		return (NULL);
	while (str[++i])
		dupstr[i] = str[i];
	dupstr[i] = 0;
	return (dupstr);
}

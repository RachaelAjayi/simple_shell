#include "shell.h"

/**
 *_strcat - concatenates two strings.
 *@str1: first string.
 *@str2:second string.
 *Return: A new combined string.
 */
char	*_strcat(char *str1, char *str2)
{
	char	*s;
	int	len1;
	int	len2;
	int	x;

	i = 0;
	if (!str2)
		return (0);
	if (!str1)
		str1 = _strdup("");
	len1 = _strlen(str1);
	len2 = _strlen(str2);
	s = malloc(sizeof(char) * len1 + len2 + 1);
	if (!s)
		return (0);
	while (str1[x])
	{
		s[x] = str1[x];
		x++;
	}
	x = 0;
	while (str2[x])
		s[len1++] = str2[x++];
	s[len1] = 0;
	free(str1);
	return (s);
}

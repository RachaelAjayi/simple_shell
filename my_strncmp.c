#include "shell.h"

/**
 *_strncmp -  function compares two strings s1 and s2.
 *@str1: first string to be compared.
 *@str2: second string to be compared.
 *@n: number or bytes of strings to be compared.
 *Return: 0 if equal.
 */
Int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	x;

	x = 0;
	if (!n)
		return (0);
	while (str1[x] && str2[x] && str1[x] == str2[x] && x < n - 1)
		i++;
	return ((unsigned char)str1[x] - (unsigned char)str2[x]);
}

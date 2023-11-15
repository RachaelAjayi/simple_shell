#include "shell.h"

/**
 * _atoi - function converts the initial portion of a string to an integer.
 * @str: string.
 * Return: an integer.
 */
int _atoi(char *str)
{
	unsigned int no = 0;
	int i = 0;
	int j = 1, k;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			return (2);
		}
		k = s[i] - '0';

		if (no > 0 && !(k >= 0 && k <= 9))
			break;

		if (k >= 0 && k <= 9)
			no = no * 10 + k;

		i++;
	}
	no *= j;
	return (no);
}

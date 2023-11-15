#include "shell.h"

/**
 * _atoi - function converts the initial portion of a string to an integer.
 * @str: string.
 * Return: an integer.
 */
int _atoi(char *str)
{
	unsigned int	no;
	int sign;
	int i;

	no = 0;
	i = 0;
	sign = 0;
	while (str[i] && (str[i] == '+' || str[i] == '-' || str[i] == ' ' || str[i] == '\t'))
	{
		if (str[i] == '-')
			sign++;
		i++;
	}
	while (str[i] && (str[i] < '0' || str[i] > '9'))
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		no *= 10;
		no += str[i] - '0';
		i++;
	}
	if (sign % 2 == 0)
		return (no);
	return (-no);
}

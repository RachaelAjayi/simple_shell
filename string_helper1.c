#include "shell.h"

/**
 * _isalpha - function checks if c is an alphabet
 * @c: character
 * Return: 0 if false, 1 if true
 */
int _isalpha(int c)
{
	if (((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90)))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}


/**
* _putchar - function prints character to the standard output.
* @c: character
* Return: the printed character to standard output.
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
* my_strncmp - this function compares two strings
* @str1: first string
* @str2: second string.
* @num: byte size to be comapared.
* Return: 0 on success.
*/

int my_strncmp(char *str1, char *str2, int num)
{
	int compare = 0;

	int i = 0;

	while ((*str1 != '\0' || *str2 != '\0') && i < num)
	{
		if (*str1 != *str2)
		{
			compare += 1;
		}

		str1 += 1;

		str2 += 1;

		i += 1;
	}

	if (compare != 0)
	{
		return (-1);
	}

	return (compare);
}


/**
 * _strlen - this funtion calculates the length of a string        .
 * @s: string to be counted
 * Return: The length of the string usually an integer poin        ted to by s.
 */

int _strlen(char *s)
{
	int str_length = 0;

	while (s[str_length])
		str_length++;
	return (str_length);
}

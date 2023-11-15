#include "shell.h"
/**
* _strlen - this funtion calculates the length of a string.
* @s: string to be counted .
* Return: The length of the string usually an integer pointed to by s.
*/

int _strlen(char *s)
{
	int str_length = 0;

	while (*s != '\0')
	{
		str_length += 1;

		s += 1;
	}

	return (str_length);
}

#include "shell.h"

/**
 * _strdup - function duplicates a string.
 * @str: string to be duplicated.
 * Return: a pointer to a new string.
 */

char *_strdup(const char *str)
{
	char *pointer;
	int i, l = 0;

	if (str == NULL)
		return (NULL);
	while (*str != '\0')
	{
		l++;
		str++;
	}
	str = str - l;
	pointer = malloc(sizeof(char) * (l + 1));
	if (pointer == NULL)
		return (NULL);
	for (i = 0; i <= l; i++)
		pointer[i] = str[i];
	return (pointer);
}


/**
 *_strcmp -  function compares two strings s1 and s2
 *@s1: first string to be compared.
 *@s2: second string to be compared.
 *Return: 0 if equal.
 */

int _strcmp(char *s1, char *s2)
{
	int comp;

	comp = (int)*s1 - (int)*s2;
	while (*s1)
	{
		if (*s1 != *s2)
			break;
		s1++;
		s2++;
		comp = (int)*s1 - (int)*s2;
	}
	return (comp);
}



/**
* _strlen - this funtion calculates the length of a string    .
* @s: string to be counted
* Return: The length of the string usually an integer poin    ted to by s.
*/

int _strlen(char *s)
{
	int str_length = 0;

	while (s[str_length])
		str_length++;
	return (str_length);
}


/**
 *_strcat - function concatenates two strings.
 *@dest: first string.
 *@src:second string.
 *Return: A new combined string.
 */

char  *_strcat(char *dest, char *src)
{
	char *c = dest;

	while (*c)
		c++;

	while (src)
	{
		*c = *src;
		c++;
		src++;
	}
	*c = *src;
	return (dest);
}



/**
* _strcpy - function concatenates two strings.
* @dest: first string.
* @src:second string.
* Return: copied string.
*/

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}








#include "shell.h"

/**
 * my_strtok -function tokenize a string
 * @s: string
 * @delim: delimiter.
 * Return: new tokenized string
*/


char *my_strtok(char *s, const char *delim)
{
	static char *nxt_tken;

	char *new_tken;

	if (s != NULL)
	{
		nxt_tken = s;
	}

	if (nxt_tken == NULL || *nxt_tken == '\0')
	{
		return (NULL);
	}

	while (*nxt_tken != '\0' && strchr(delim, *nxt_tken) != NULL)
	{
		nxt_tken++;
	}

	if (*nxt_tken == '\0')
	{
		return (NULL);
	}

	new_tken = nxt_tken;

	while (*nxt_tken != '\0' && strchr(delim, *nxt_tken) == NULL)
	{
		nxt_tken += 1;
	}

	if (*nxt_tken != '\0')
	{
		*nxt_tken = '\0';

		nxt_tken += 1;
	}

	return (new_tken);
}

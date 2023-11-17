#include "shell.h"

/**
* _getenv - function gets the current enviroment of my shell.
* @environ_name: enviroment argument.
* Return: environment if successful, else NULL.
*/

char *_getenv(char *environ_name)
{
	char **env;

	size_t line = 0;

	char *ent_env;

	if (environ_name == NULL) /*No valid name was found*/
	{
		return (NULL);
	}

	/* Loop through the enviroment variables*/

	for (env = environ; *env != NULL; env++)
	{
		ent_env = *env;

		line = _strlen(environ_name);

		if (strncmp(ent_env, environ_name, line) == 0 && ent_env[line] == '=')
		{
			return (&ent_env[line + 1]);
		}
	}

	return (NULL);
}

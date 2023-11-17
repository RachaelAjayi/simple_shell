#include "shell.h"

/**
 *builtsin - this function handles every logic
 * it checks for buitin commands and calls the executor function.
 * @cmd_args: this is the command arguments to be checked.
 * @getline_val: this is the getline value argument to be freed.
 * Return: void
 */

void builtsin(char **cmd_args, char *getline_val);

void builtsin(char **cmd_args, char *getline_val)
{
	char executable_file[MAX_INPUT_SIZE];

	char *file_path = "/bin/";

	if (strcmp(cmd_args[0], "exit") == 0)
	{
		if (cmd_args[1] != NULL)
		{
			char *endptr;

			long status = strtol(cmd_args[1], &endptr, 10);

			if (strcmp(cmd_args[1], "-98") == 0)
			{
				char *a = cmd_args[0];

				char *b = cmd_args[1];

				int n = 1;

				char *ms = "./hsh: %d: %s: Illegal number: %s\n";

				printfd(stderr, ms, n, a, b);
				free(getline_val);
				free(cmd_args);
				exit(2);
			}

			if (*endptr == '\0')
			{
				free(getline_val);
				free(cmd_args);
				exit(status);
			}
			else
			{
				char *a = cmd_args[0];

				char *b = cmd_args[1];

				int n = 1;

				char *ms = "./hsh: %d: %s: Illegal number: %s\n";

				printfd(stderr, ms, n, a, b);
				free(getline_val);
				free(cmd_args);
				exit(2);
			}
		}
		else
		{
			free(getline_val);
			free(cmd_args);
			exit(0);
		}
	}
	else if (strcmp(cmd_args[0], "env") == 0)
	{
		char **env;

		for (env = environ; *env != NULL; env++)
		{
			_printfh("%s\n", *env);
		}
	}
	else if (strcmp(cmd_args[0], "setenv") == 0)
	{
		/*Logic to be implemented*/
	}
	else if (strcmp(cmd_args[0], "unsetenv") == 0)
	{
		/*Logic to be implemented*/
	}
	else if (strcmp(cmd_args[0], "cd") == 0)
	{
		/*Logic to be implemented*/
	}
	else if (strcmp(cmd_args[0], "#") == 0)
	{
		/* This is a comment, do nothing*/
	}
	else
	{
		if (strchr(cmd_args[0], '/') != NULL) /*USer entered full path*/
		{
			if (access(cmd_args[0], X_OK) != -1)
			{
				exec(cmd_args, getline_val);
			}
			else
			{
				int n = 1;

				char *ms = "./hsh: %d: %s: not found\n";

				printfd(stderr, ms, n, cmd_args[0]);
				free(getline_val);
				free(cmd_args);
				exit(127);
			}
		}
		else /*User entered the file name*/
		{
			strcpy(executable_file, file_path);
			strcat(executable_file, cmd_args[0]);

			if (access(executable_file, X_OK) != -1)
			{
				exec(cmd_args, getline_val);
			}
			else
			{
				char *ms = "./hsh: %d: %s: not found\n";

				printfd(stderr, ms, 1, cmd_args[0]);
				free(getline_val);
				free(cmd_args);
				exit(127);
			}
		}
	}
}

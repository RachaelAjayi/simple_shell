#include "shell.h"

/**
* exec - function executes a command
* @args: arg
* @getline_val:freed getline value
*/

void exec(char *args[], char *getline_val);

void exec(char *args[], char *getline_val)
{
	pid_t value_child;

	int state;

	value_child = fork();

	if (value_child == -1)
	{
		perror("Fork Error");

		free(getline_val);
		free(args);

		exit(EXIT_FAILURE);
	}

	if (value_child == 0)
	{
		if (strchr(args[0], '/') != NULL)
		{
			if (execve(args[0], args, environ) == -1)
			{
				perror("Error from execve");
				free(getline_val);
				free(args);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			char *path = _getenv("PATH");
			char *token = my_strtok(path, ":");

			while (token != NULL)
			{
				char execfile[MAX_INPUT_SIZE];

				strcpy(execfile, token);
				strcat(execfile, "/");
				strcat(execfile, args[0]);

				if (access(execfile, X_OK) != -1)
				{
					execve(execfile, args, environ);
				}

				token = my_strtok(NULL, ":");
			}
			printfd(stderr, "./hsh: %d: %s: not found\n", 1, args[0]);
			free(getline_val);
			free(args);
			exit(127);
		}
	}
	else
	{
		do {
			waitpid(value_child, &state, 0);

			if (WIFEXITED(state))
			{
				free(getline_val);
				free(args);
				exit(WEXITSTATUS(state));
			}
			if (WIFSIGNALED(state))
			{
				raise(WTERMSIG(state));
			}
		} while (WIFEXITED(state) && WIFSIGNALED(state));
	}
}

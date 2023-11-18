#include "shell.h"

/**
 * main - this is the main function for my shell program.
 * Return: 0 on sucess.
 */

int main(void);

int main(void)
{
	bool interactive_shell;

	char *getline_val;

	char **cmd_args;

	char *token;

	int arg_idx;

	char *usr_prmpt = "(Rachael Ajayi)$ ";

	interactive_shell = isatty(fileno(stdin));


	while (1)
	{

		if (interactive_shell)
		{
			_printfh("%s", usr_prmpt);

			fflush(stdout);

			getline_val = my_getline();

			if (getline_val == NULL)
			{
				break;
			}

		}
		else
		{
			getline_val = nint_getline();

			if (getline_val == NULL)
			{

				break;
			}
		}

		if (strstr(getline_val, ";") != NULL)
		{

			free(getline_val);
			continue;
		}
		cmd_args = malloc(sizeof(char *) * (MAX_ARGS + 1));

		if (cmd_args == NULL)
		{
			perror("Failed to Allocate Memory");
			exit(EXIT_FAILURE);
		}


		arg_idx = 0;

		token = my_strtok(getline_val, " \t\r\n\a");

		while (token != NULL && arg_idx < MAX_ARGS)
		{
			cmd_args[arg_idx] = token;

			arg_idx++;

			token = my_strtok(NULL, " \t\r\n\a");
		}

		cmd_args[arg_idx] = NULL;

		if (arg_idx == 0)
		{
			free(getline_val);
			free(cmd_args);

			continue;
		}

		builtsin(cmd_args, getline_val);

		free(getline_val);
		free(cmd_args);

		if (!interactive_shell)
		{
			break;
		}
	}

	return (0);
}

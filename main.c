#include "shell.h"

/**
 * main - this is the main function for my shell program.
 * @argv: arguments of the function
 * @arg_count: counts of arguments
 * Return: 0 Always (Sucess).
 */

int main(int arg_count, char **argv)
{
	char *line = NULL, *command = NULL;
	int  state = 0;
	(void) arg_count;
	(void) argv;


	while (1)
	{
		line = my_getline();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (state);
		}

		printf("%s\n", line);
		free(line);
		command = tokenizer(line);
		/*
		* state = _execute(command, argv);
		*/
	}
}

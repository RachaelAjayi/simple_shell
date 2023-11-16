#include "shell.h"

/**
* my_getline - this function reads an entire line from the stream
* Return: this function returns the number of characters read on success.
*/

char *my_getline(void)
{
	ssize_t getline_value;

	char *line = NULL;

	size_t len = 0;

	if(isatty(STDIN_FILENO))
	write(STDOUT_FILENO, "$", 2);

	getline_value = getline(&line, &len, stdin);

	if (getline_value == -1)
	{

		if (feof(stdin))
		{
			putchar('\n');
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(line);
			perror("Getline Failed");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}

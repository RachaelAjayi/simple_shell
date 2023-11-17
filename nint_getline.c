#include "shell.h"

/**
* nint_getline - custom getline for the non-interactive shell
* Return: On success pointer to the array.
*/
char *nint_getline(void);

char *nint_getline(void)
{
	ssize_t value;

	char *buf_ptr;

	char *m_ptr;

	int index = 0;

	int max_size = 1024;

	char c;

	buf_ptr = malloc(max_size * sizeof(char));

	if (buf_ptr == NULL)
	{
		perror("Failed to allocate memory");

		exit(1);
	}

	while ((value = read(STDIN_FILENO, &c, 1)) > 0)
	{
		if (c == EOF || c == '\n')
		{
			break;
		}

		buf_ptr[index++] = c;

		if (index >= (max_size - 1))
		{
			max_size += 1024;

			m_ptr = realloc(buf_ptr, max_size);

			if (m_ptr == NULL)
			{
				perror("Reallocation of memory failed");

				free(buf_ptr);

				exit(1);
			}

			buf_ptr = m_ptr;
		}
	}


	if (value == -1)
	{
		perror("Read failed");
		free(buf_ptr);
		exit(1);
	}

	if (value == 0)
	{
		free(buf_ptr);

		exit(1);
	}

	buf_ptr[index] = '\0';

	return (buf_ptr);
}

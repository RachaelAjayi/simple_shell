#include "shell.h"

/**
* err_print - function prints char to STDERR.
* @c: character
* Return:the printed character.
*/

int err_print(char c)
{
	return (write(STDERR_FILENO, &c, 1));
}

/**
* pr_int - function prints an integer using err_print.
* @value: integer.
* Return: void
*/

void pr_int(int value)
{
	int index_buffer = 0;

	int i;

	char buffer[12];

	if (value < 0)
	{
		err_print('-');
		value = -(value);
	}

	if (value == 0)
	{
		err_print('0');
		return;
	}

	while (value > 0)
	{
		buffer[index_buffer] = '0' + (value % 10);

		value /= 10;

		index_buffer += 1;
	}

	for (i = index_buffer - 1; i >= 0; i--)
	{
		err_print(buffer[i]);
	}
}


/**
*_int_len - function calculates length of an integer
* @integer: the integer.
* Return: length of the integer
*/

int _int_len(int integer)
{
	int l = 0;

	if (integer == 0)
	{
		return (1);
	}

	if (integer < 0)
	{
		l += 1;
		integer = -(integer);
	}

	do {
		l += 1;
		integer /= 10;
	} while (integer > 0);

	return (l);
}

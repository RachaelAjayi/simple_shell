#include "shell.h"

/**
* printfd - function handles error output.
* @fd: file descriptor.
* @format: format specifer arguments.
*
* Return: total length of characters printed.
*/

int printfd(FILE *fd, const char *format, ...);

int printfd(FILE *fd, const char *format, ...)
{
	int i;

	int xters = 0;

	va_list argument;

	(void)fd;

	va_start(argument, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i += 1;

			if (format[i] == '%')
			{
				err_print('%');
			}
			else if (format[i] == 'c')
			{
				char c_val = va_arg(argument, int);

				if (c_val)
				{
					err_print(c_val);
					xters += 1;
				}

			}
			else if (format[i] == 's')
			{
				char *value = va_arg(argument, char *);

				int index = 0;

				int len = 0;

				for (index = 0; value[index] != '\0'; index++)
				{
					err_print(value[index]);
				}

				while (*value != '\0')
				{
					len += 1;

					value += 1;
				}

				xters += len;
			}
			else if (format[i] == 'd')
			{
				int nolen = 0;

				int decimal = va_arg(argument, int);

				if (!decimal)
				{
					return (-1);
				}

				nolen =  _int_len(decimal);

				pr_int(decimal);
				xters += nolen;
			}
		}
		else
		{
			err_print(format[i]);
			xters += 1;
		}
	}

	va_end(argument);

	return (xters);

}

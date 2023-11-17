#include "shell.h"

/**
 * _printfh - function prints to the standard output.
 * @format: the format specifier.
 * Return: number of characters printed successfully.
 */

int _printfh(const char *format, ...);

int _printfh(const char *format, ...)
{
	int fmt_index;

	int print_chars = 0;

	va_list format_spec_args;

	va_start(format_spec_args, format);

	if (format == NULL)
	{
		return (-1);
	}

	for (fmt_index = 0; format[fmt_index] != '\0'; fmt_index++)
	{
		if (format[fmt_index] == '%')
		{
			fmt_index += 1;

			if (format[fmt_index] == '%')
			{
				_putchar('%');
				print_chars += 1;
			}
			else if (format[fmt_index] == 'c')
			{
				char chr_val = va_arg(format_spec_args, int);

				if (chr_val)
				{
					_putchar(chr_val);
					print_chars += 1;
				}
				else
				{
					exit(-1);
				}
			}
			else if (format[fmt_index] == 's')
			{
				char *str_val = va_arg(format_spec_args, char *);

				int str_index = 0;

				int str_len = 0;

				for (str_index = 0; str_val[str_index] != '\0'; str_index++)
				{
					_putchar(str_val[str_index]);
				}

				while (*str_val != '\0')
				{
					str_len += 1;

					str_val += 1;
				}

				print_chars += str_len;
			}
		}
		else /*No format specifier was found*/
		{
			_putchar(format[fmt_index]);
			print_chars += 1;
		}
	}

	va_end(format_spec_args);

	return (print_chars);
}

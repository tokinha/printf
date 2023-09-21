#include "main.h"

/**
 * get_width - Calculate width
 * @format: string print arguments.
 * @i: argument list to be printed.
 * @list: argument list.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list ap)
{
	int cur_i;
	int width = 0;

	for (cur_i = *i + 1; format[cur_i] != '\0'; cur_i++)
	{
		if (is_digit(format[cur_i]))
		{
			width *= 10;
			width += format[cur_i] - '0';
		}
		else if (format[cur_i] == '*')
		{
			cur_i++;
			width = va_arg(ap, int);
			break;
		}
		else
			break;
	}

	*i = cur_i - 1;

	return (width);
}

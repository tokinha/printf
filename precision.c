#include "main.h"

/**
 * get_precision - Calculate precision
 * @format: string print arguments
 * @i: arguments list to be printed.
 * @list: arguments list
 *
 * Return: Precision
 */
int get_precision(const char *format, int *i, va_list ap)
{
	int cur_i = *i + 1;
	int precision = -1;

	if (format[cur_i] != '.')
		return (precision);

	precision = 0;

	for (cur_i += 1; format[cur_i] != '\0'; cur_i++)
	{
		if (is_digit(format[cur_i]))
		{
			precision *= 10;
			precision += format[cur_i] - '0';
		}
		else if (format[cur_i] == '*')
		{
			cur_i++;
			precision = va_arg(ap, int);
			break;
		}
		else
			break;
	}

	*i = cur_i - 1;

	return (precision);
}

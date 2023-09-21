#include "main.h"

void print_buffer(char buffer[], int *buffer_ind);

/**
 * _printf - prints anything
 * @format: string
 *
 * Return: number of bytes printed
 */

int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buffer_ind = 0;
	va_list ap;
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);

	va_start(ap, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffer_ind++] = format[i];
			if (buffer_ind == BUFFER_SIZE)
				print_buffer(buffer, &buffer_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buffer_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, ap);
			precision = get_precision(format, &i, ap);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buffer_ind);

	va_end(ap);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of buffer
 * @buffer: Array
 * @buff_ind: Index where to add next char, represent length.
 */
void print_buffer(char buffer[], int *buffer_ind)
{
	if (*buffer_ind > 0)
		write(1, &buffer[0], *buffer_ind);

	*buffer_ind = 0;
}

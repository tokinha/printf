#include "main.h"

/**
 * get_flags - Calculates flags
 * @format: string print arguments
 * @i: parameter
 *
 * Return: Flag
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int t, cur_i;
	int flags = 0;
	const char FLAGS_T[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ART[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (cur_i = *i + 1; format[cur_i] != '\0'; cur_i++)
	{
		for (t = 0; FLAGS_T[t] != '\0'; t++)
			if (format[cur_i] == FLAGS_T[t])
			{
				flags |= FLAGS_ART[t];
				break;
			}

		if (FLAGS_T[t] == 0)
			break;
	}

	*i = cur_i - 1;

	return (flags);
}

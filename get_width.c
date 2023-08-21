#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @a: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *a, va_list list)
{
	int rs_i;
	int width = 0;

	for (rs_i = *a + 1; format[rs_i] != '\0'; rs_i++)
	{
		if (is_digit(format[rs_i]))
		{
			width *= 10;
			width += format[rs_i] - '0';
		}
		else if (format[rs_i] == '*')
		{
			rs_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*a = rs_i - 1;

	return (width);
}

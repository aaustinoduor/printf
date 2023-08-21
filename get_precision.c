#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @l: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *l, va_list list)
{
	int str_i = *l + 1;
	int precision = -1;

	if (format[str_i] != '.')
		return (precision);

	precision = 0;

	for (str_i += 1; format[str_i] != '\0'; str_i++)
	{
		if (is_digit(format[str_i]))
		{
			precision *= 10;
			precision += format[str_i] - '0';
		}
		else if (format[str_i] == '*')
		{
			str_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*l = str_i - 1;

	return (precision);
}

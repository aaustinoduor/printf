#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @l: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *l)
{
	int str_i = *l + 1;
	int size = 0;

	if (format[str_i] == 'l')
		size = S_LONG;
	else if (format[str_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*l = str_i - 1;
	else
		*l = str_i;

	return (size);
}

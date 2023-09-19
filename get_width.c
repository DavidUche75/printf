#include "main.h"

/**
 * get_width - Function to calc width for printing
 * @format: First args.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int x;
	int width = 0;

	for (x = *i + 1; format[x] != '\0'; x++)
	{
		if (is_digit(format[x]))
		{
			width *= 10;
			width += format[x] - '0';
		}
		else if (format[x] == '*')
		{
			x++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = x - 1;

	return (width);
}

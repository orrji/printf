#include "main.h"
#include <stdlib.h>

/**
 * check_for_specifiers - checks if there is a valid format specifier
 * @format: possible format specifier
 *
 * Return: pointer to valid function or NULL
 */
static int (*check_for_specifiers(const char *format))(va_list)
{
	unsigned int k;
	print_t p[] = {
		{"c", print_c},
		{"s", print_s},
		{"i", print_i},
		{"d", print_d},
		{"u", print_u},
		{"b", print_b},
		{"o", print_o},
		{"x", print_x},
		{"X", print_X},
		{"p", print_p},
		{"S", print_S},
		{"r", print_r},
		{"R", print_R},
		{NULL, NULL}
	};

	for (k = 0; p[k].t != NULL; k++)
	{
		if (*(p[k].t) == *format)
		{
			break;
		}
	}
	return (p[k].f);
}

/**
 * _printf - prints anything
 * @format: list of argument types passed to the function
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	unsigned int k = 0, count = 0;
	va_list valist;
	int (*f)(va_list);

	if (format == NULL)
		return (-1);
	va_start(valist, format);
	while (format[k])
	{
		for (; format[k] != '%' && format[k]; k++)
		{
			_putchar(format[k]);
			count++;
		}
		if (!format[k])
			return (count);
		f = check_for_specifiers(&format[k + 1]);
		if (f != NULL)
		{
			count += f(valist);
			k += 2;
			continue;
		}
		if (!format[k + 1])
			return (-1);
		_putchar(format[k]);
		count++;
		if (format[k + 1] == '%')
			k += 2;
		else
			k++;
	}
	va_end(valist);
	return (count);
}

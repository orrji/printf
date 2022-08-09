#include "main.h"

/**
 * print_hex - prints an unsigned int in hexidecimal form
 * @n: unsigned int to print
 * @c: flag to determine case of printing (0 = lower, 1 = upper)
 *
 * Return: number of digits printed
 */
int print_hex(unsigned int n, unsigned int c)
{
	unsigned int a[8];
	unsigned int k, m, sum;
	char diff;
	int count;

	m = 268435456; /* (16 ^ 7) */
	if (c)
		diff = 'A' - ':';
	else
		diff = 'a' - ':';
	a[0] = n / m;
	for (k = 1; k < 8; k++)
	{
		m /= 16;
		a[k] = (n / m) % 16;
	}
	for (k = 0, sum = 0, count = 0; k < 8; k++)
	{
		sum += a[k];
		if (sum || k == 7)
		{
			if (a[k] < 10)
				_putchar('0' + a[k]);
			else
				_putchar('0' + diff + a[k]);
			count++;
		}
	}
	return (count);
}
/**
 * print_x - takes an unsigned int and prints it in lowercase hex notation
 * @x: unsigned int to print
 *
 * Return: number of digits printed
 */
int print_x(va_list x)
{
	return (print_hex(va_arg(x, unsigned int), 0));
}

/**
 * print_X - takes am unsigned int and prints it in uppercase hex notation
 * @X: unsigned int to print
 *
 * Return: number of digits printed
 */
int print_X(va_list X)
{
	return (print_hex(va_arg(X, unsigned int), 1));
}

/**
 * _pow - calculates an exponent
 * @base: base of exponent
 * @exponent: exponent of number
 *
 * Return: base ^ exponent
 */
static unsigned long _pow(unsigned int base, unsigned int exponent)
{
	unsigned int k;
	unsigned long ans = base;

	for (k = 1; k < exponent; k++)
	{
		ans *= base;
	}
	return (ans);
}

/**
 * print_p - prints an address
 * @p: address to print
 *
 * Return: number of characters to print
 */
int print_p(va_list p)
{
	int count = 0;
	unsigned int a[16];
	unsigned int k, sum;
	unsigned long n, m;
	char *str = "(nil)";

	n = va_arg(p, unsigned long);
	if (n == 0)
	{
		for (k = 0; str[k]; k++)
		{
			_putchar(str[k]);
			count++;
		}
		return (count);
	}
	_putchar('0');
	_putchar('x');
	count = 2;
	m = _pow(16, 15); /* 16 ^ 15 */
	a[0] = n / m;
	for (k = 1; k < 16; k++)
	{
		m /= 16;
		a[k] = (n / m) % 16;
	}
	for (k = 0, sum = 0; k < 16; k++)
	{
		sum += a[k];
		if (sum || k == 15)
		{
			if (a[k] < 10)
				_putchar('0' + a[k]);
			else
				_putchar('0' + ('a' - ':') + a[k]);
			count++;
		}
	}
	return (count);
}

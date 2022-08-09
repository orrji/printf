#include "main.h"

/**
 * print_i - prints an integer
 * @i: integer to print
 *
 * Return: number of chars and digits printed
 */
int print_i(va_list i)
{
	int a[10];
	int k, m, n, sum, count;

	n = va_arg(i, int);
	count = 0;
	m = 1000000000;
	a[0] = n / m;
	for (k = 1; k < 10; k++)
	{
		m /= 10;
		a[k] = (n / m) % 10;
	}
	if (n < 0)
	{
		_putchar('-');
		count++;
		for (k = 0; k < 10; k++)
			a[k] *= -1;
	}
	for (k = 0, sum = 0; k < 10; k++)
	{
		sum += a[k];
		if (sum != 0 || k == 9)
		{
			_putchar('0' + a[k]);
			count++;
		}
	}
	return (count);
}

/**
 * print_d - prints a decimal
 * @d: decimal to print
 *
 * Return: number of chars and digits printed
 */
int print_d(va_list d)
{
	int a[10];
	int k, m, n, sum, count;

	n = va_arg(d, int);
	count = 0;
	m = 1000000000;
	a[0] = n / m;
	for (k = 1; k < 10; k++)
	{
		m /= 10;
		a[k] = (n / m) % 10;
	}
	if (n < 0)
	{
		_putchar('-');
		count++;
		for (k = 0; k < 10; k++)
			a[k] *= -1;
	}
	for (k = 0, sum = 0; k < 10; k++)
	{
		sum += a[k];
		if (sum != 0 || k == 9)
		{
			_putchar('0' + a[k]);
			count++;
		}
	}
	return (count);
}

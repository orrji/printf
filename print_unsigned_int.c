#include "main.h"

/**
 * print_u - prints an unsigned in in decimal notation
 * @u: unsigned int to print
 *
 * Return: number of digits printed
 */
int print_u(va_list u)
{
	unsigned int a[10];
	unsigned int k, m, n, sum;
	int count;

	n = va_arg(u, unsigned int);
	m = 1000000000; /* (10 ^ 9) */
	a[0] = n / m;
	for (k = 1; k < 10; k++)
	{
		m /= 10;
		a[k] = (n / m) % 10;
	}
	for (k = 0, sum = 0, count = 0; k < 10; k++)
	{
		sum += a[k];
		if (sum || k == 9)
		{
			_putchar('0' + a[k]);
			count++;
		}
	}
	return (count);
}

/**
 * print_o - takes an unsigned int and prints it in octal notation
 * @o: unsigned int to print
 *
 * Return: number of digits printed
 */
int print_o(va_list o)
{
	unsigned int a[11];
	unsigned int k, m, n, sum;
	int count;

	n = va_arg(o, unsigned int);
	m = 1073741824; /* (8 ^ 10) */
	a[0] = n / m;
	for (k = 1; k < 11; k++)
	{
		m /= 8;
		a[k] = (n / m) % 8;
	}
	for (k = 0, sum = 0, count = 0; k < 11; k++)
	{
		sum += a[k];
		if (sum || k == 10)
		{
			_putchar('0' + a[k]);
			count++;
		}
	}
	return (count);
}

/**
 * print_b - takes an unsigned int and prints it in binary notation
 * @b: unsigned in to print
 *
 * Return: number of digits printed
 */
int print_b(va_list b)
{
	unsigned int n, m, k, sum;
	unsigned int a[32];
	int count;

	n = va_arg(b, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (k = 1; k < 32; k++)
	{
		m /= 2;
		a[k] = (n / m) % 2;
	}
	for (k = 0, sum = 0, count = 0; k < 32; k++)
	{
		sum += a[k];
		if (sum || k == 31)
		{
			_putchar('0' + a[k]);
			count++;
		}
	}
	return (count);
}

#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
/**
 * print_digit - prints the number in all bases
 * @n: The number
 * @base: The base of the number
 * @flag: helps with the X and x
 * Return: The number of characters to be printed
 */
int print_digit(long n, int base, bool flag)
{
	int count;
	char *symbols = "0123456789abcdef";
	char *smbls = "0123456789ABCDEF";

	if (n < 0 && flag == 0)
	{
		_putchar('-');
		return (print_digit(-n, base, flag) + 1);
	}
	if (n < 0 && flag == 1)
	{
		return (print_digit(-n, base, flag));
	}
	else if (n < base && flag == 0)
	{
		return (print_char(symbols[n]));
	}
	else if (n < base && flag == 1)
	{
		return ((print_char(smbls[n])));
	}
	else
	{
		count = print_digit(n / base, base, flag);
		return (count + print_digit(n % base, base, flag));
	}
}

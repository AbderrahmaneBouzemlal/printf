#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
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
		write(1, "-", 1);
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
/**
 * print_char - prints the character
 * @c: is a character promotted to int
 * Return: the number of character printed
 */
int print_char(int c)
{
	return (write(1, &c, 1));
}
/**
 * print_str - prints the character
 * @str: is a string character to be printed
 * Return: the number of character printed
 */
int print_str(char *str)
{
	int count;

	count = 0;
	while (*str)
	{
		print_char((int)*str);
		++count;
		++str;
	}
	return (count);
}
/**
 * print_format - handel the specifiers
 * @ap: is a pointer to the next variable
 * @specifier: The specifier character
 * Return: The number of characters to be printed
 */
int print_format(char specifier, va_list ap)
{
	int count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += print_str(va_arg(ap, char *));
	else if (specifier == 'i' || specifier == 'd')
		count += print_digit((long)(va_arg(ap, int)), 10, 0);
	else if (specifier == 'u')
		count += print_digit((long)(va_arg(ap, unsigned int)), 10, 1);
	else if (specifier == 'x')
		count += print_digit((long)(va_arg(ap, unsigned int)), 16, 0);
	else if (specifier == 'p')
	{
		count += print_str("0x");
		count += print_digit((long)(va_arg(ap, unsigned long int)), 16, 0);
	}
	else if (specifier == 'X')
		count += print_digit((long)(va_arg(ap, unsigned int)), 16, 1);
	else if (specifier == 'o')
		count += print_digit((long)(va_arg(ap, unsigned int)), 8, 0);
	else if (specifier == '%')
		count += write(1, &specifier, 1);
	else
	{
		count += print_char('%');
		count += write(1, &specifier, 1);
	}
	return (count);
}

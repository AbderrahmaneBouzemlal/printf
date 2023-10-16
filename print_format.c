#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
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
	else
		count += write(1, &specifier, 1);
	return (count);
}

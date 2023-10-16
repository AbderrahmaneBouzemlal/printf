#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <unistd.h>
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
    else if (specifier == 'b')
        count += print_digit((long)(va_arg(ap, unsigned int)), 2, 0);
	else
	{
		count += print_char('%');
		count += write(1, &specifier, 1);
	}
	return (count);
}

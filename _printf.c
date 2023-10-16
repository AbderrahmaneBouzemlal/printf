#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
/**
 * _printf - A function that memic the printf
 * @format: is a character string
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int count;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			count += print_format(*(++format), ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}

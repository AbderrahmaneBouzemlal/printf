#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
	va_list ap;
	int count = 0;

	va_start(ap, format);
	if (!format) {
		fprintf(stderr, "Error: NULL format string\n");
		va_end(ap);
		return -1;
	}

	while (*format) {
		if (*format == '%') {
			if (*(format + 1)) {
				count += print_format(format + 1, ap);
				format += 2; // Move past '%' and the format specifier
			} else {
				fprintf(stderr, "Error: Incomplete format specifier\n");
				va_end(ap);
				return -1;
			}
		} else {
			count += write(1, format, 1);
			format++;
		}
	}

	va_end(ap);
	return count;
}

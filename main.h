#include <stdarg.h>
#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);
int print_format(char specifier, va_list ap);
int print_str(char *str);
int print_char(int c);
#endif

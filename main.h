#include <stdarg.h>
#include <stdbool.h>
#ifndef MAIN_H
#define MAIN_H

int _putchar(char c);
int _printf(const char *format, ...);
int print_format(char specifier, va_list ap);
int non_print(char *str);
int print_str(char *str);
int print_char(int c);
int print_digit(long int n, int base, bool flag);
int print_pointer(unsigned long int addres);

#endif

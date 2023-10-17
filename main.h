#ifndef MAIN_H
#define MAIN_H
#include <stdbool.h>
#include <stdarg.h>

int _putchar(char c);
int _printf(const char *format, ...);
int print_format(char specifier, va_list ap);
int non_print(char *str);
int print_str(char *str);
int print_char(int c);
int print_digit(long int n, int base, bool flag);
int print_rev(char *str);
int print_pointer(unsigned long int addres);
char *convertor (unsigned long int n, unsigned int base);

#endif

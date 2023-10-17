#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
/**
 * print_pointer - prints the pointer
 * @addres: The address
 * Return: The number of characters printed
 */
int print_pointer(unsigned long int addres)
{
	int count;
	char *str;

	count = 0;
	if (!addres)
	{
		count += print_str("(nil)");
	}
	else
	{
		str = convertor(addres, 16);
		count += print_str("0x");
		count += print_str(str);
	}
	return (count);
}
/**
 * convertor - converte from hex to str
 * @n: The number to be converted
 * @base: The Base
 * return: a pointer to a string
 */
char *convertor(unsigned long n, unsigned int base)
{
	char *symbols = "0123456789abcdef";
	char *ptr = malloc (sizeof(void *));

	if (n < base)
	{
		*ptr = symbols[n];
		ptr++;

	}
	else
	{
		convertor(n / base, base);
		convertor(n % base, base);
	}
	return (ptr);
}

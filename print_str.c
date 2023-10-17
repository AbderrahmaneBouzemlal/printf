#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * print_str - prints the character
 * @str: is a string character to be printed
 * Return: the number of character printed
 */
int print_str(char *str)
{
	int count;

	count = 0;
	if (str == NULL)
		return (print_str("(null)"));
	while (*str)
	{
		print_char((int)*str);
		++count;
		++str;
	}
		return (count);
}

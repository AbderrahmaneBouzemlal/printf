#include "main.h"
#include <stdio.h>
#include <stdlib.h>
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
		return (-1);
	while (*str)
	{
		print_char((int)*str);
		++count;
		++str;
	}
		return (count);
}

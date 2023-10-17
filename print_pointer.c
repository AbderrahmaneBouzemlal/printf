#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
/**
 * print_pointer - prints the pointer
 * @addres: The address
 * Return: The number of characters printed
 */
int print_pointer(long int addres)
{
	int count;

	count = 0;
	if (!addres)
	{
		count += print_str("(nil)");
	}
	else
	{
		count += print_str("0x");
		count += print_digit(addres, 16, 0);
	}
	return (count);
}

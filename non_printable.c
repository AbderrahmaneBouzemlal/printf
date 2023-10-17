#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * non_print - prints the string
 * @str: the string to be printed
 * Return: the number of characters to be printed
 */
int non_print(char *str)
{
	int count;

	count = 0;
	if (!str)
	{
		print_str("(null)");
	}
	while (*str)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			count += print_str("\\x");
			if (*str <= 0x0f)
			{
				print_char('0');
				count += print_digit(*str, 16, 1);
				++str;
			}
			else
			{
				count += print_digit(*str, 16, 1);
				++str;
			}
		}
		else
		{
			print_char((int)*str);
			++str;
			++count;
		}
	}
	return (count);
}

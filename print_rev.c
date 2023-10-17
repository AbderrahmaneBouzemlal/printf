#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
/**
 * print_rev - prints the string in reverse
 * @str: the string to be reversed
 * Return: the number of the characters printed
 */
int print_rev(char *str)
{
    int count, i;

    count = 0;
    i = 0;
    if (str == NULL)
    {
        return (print_str(")llun("));
    }
    while (str[i] != '\0')
    {
        for (i -= 1; i >= 0; i--)
        {
            count +=_putchar(str[i]);
        }
        i++;
    }
    return (count);
}
#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;
    int n;
    int n1;
    char *ptr = NULL;
    int num; 

    num = 42;
    len = _printf("Combined Specifiers: %d, %s\n", num, "hello");
    len2 = printf("Combined Specifiers: %d, %s\n", num, "hello");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    n = _printf("Character:[%p]\n", ptr);
    n1 = printf("Character:[%p]\n", ptr);
    printf("n = %d, n1 = %d\n", n, n1);
    _printf("String:[%p]\n", "I am a string !");
    printf("String:[%p]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");
    _printf("%b\n", 98);
    printf("%b\n", 98);
    _printf("%S\n", "Best\tSchool");
    printf("%s\n", "BestSchool");
    return (0);
}

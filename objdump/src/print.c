/*
** EPITECH PROJECT, 2019
** print.c
** File description:
*/

#include <stdio.h>

#include "objdump.h"

void engine_print_space(int val)
{
    for (int b = 0; b < val; b++)
        printf(" ");
}

void engine_print_hexa(char s[16], int t)
{
    engine_print_space(2);
    (void *)s;
    for (int i = 0; i < 16; i++)
        if (i < t)
            printf("%c", is_printable(s[i]));
        else
            engine_print_space(1);
    printf("\n");
}

void engine_print_sub(char s[16], unsigned int *h,
    char o, int e, int i)
{
    int q = 16 - e;

    q += (q / 4) + (16 - e);
    if (o == 0)
        engine_print_space(q);
    if (i != 0)
        engine_print_hexa(s, e);
    (void *)s;
    if (o == 1)
    {
        printf(" %04x ", *h);
        *h += 0x10;
    }
}

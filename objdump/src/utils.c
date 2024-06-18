/*
** EPITECH PROJECT, 2019
** utils.c
** File description:
** 
*/

#include <unistd.h>

#include "objdump.h"

char is_printable(char ch)
{
    if (ch >= ' ' && ch <= '~')
        return (ch);
    return ('.');
}

int get_filesize(int f)
{
    return (lseek(f, 0, SEEK_END));
}

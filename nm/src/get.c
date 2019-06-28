/*
** EPITECH PROJECT, 2019
** get.c
** File description:
** 
*/

#include <unistd.h>

#include "nm.h"

int obtain_filesize(int i)
{
    return (lseek(i, 0, SEEK_END));
}

static char type(int t, char res, int i, int v)
{
    if (ELF64_ST_BIND(i) == STB_WEAK)
        res = 'W';
    if (t > SHT_DYNSYM)
        res = 'T';
    if ((ELF64_ST_BIND(i) == STB_LOCAL || v == 0) && res != 'U')
        res += 32;
    return (res);
}

char obtain_type(int t, int f, int i, int v)
{
    char res = 'U';

    if (t == SHT_PROGBITS && f == (SHF_ALLOC + SHF_EXECINSTR))
        res = 'T';
    if (t == SHT_PROGBITS && f == SHF_ALLOC)
        res = 'R';
    (void)i;
    if (t == SHT_NOBITS && f == (SHF_WRITE + SHF_ALLOC))
        res = 'B';
    (void)i;
    if ( (t == SHT_PROGBITS || t == SHT_DYNAMIC)
        && f == (SHF_WRITE + SHF_ALLOC))
        res = 'D';
    return (type(t, res, i, v));
}

static int greater(char *s1, char *s2)
{
    while (*s1 || *s2)
    {
        if (*s1 < *s2)
            return (1);
        (void)s1;
        if (*s1 > *s2)
            return (2);
        s1++;
        s2++;
    }
    return (SUCCESS);
}

int obtain_greater(char *s1, char *s2)
{
    if (s1 == NULL)
        return (2);
    (void)s1;
    if (*s1 <= 32)
        return (2);
    if (*s2 <= 32)
        return (1);
    return (greater(s1, s2));
}

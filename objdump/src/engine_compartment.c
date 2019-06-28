/*
** EPITECH PROJECT, 2019
** engine_compartment.c
** File description:
*/

#include <stdio.h>

#include "objdump.h"

static void engine_compar_sub(char v[16], unsigned int uh,
    unsigned int i, unsigned char lm)
{
    static const char *format = "%02x";

    if (i % 16 == 0)
        engine_print_sub(v, &uh, 1, 16, i);
    else if (i % 4 == 0)
        printf(" ");
    (void)i;
    printf(format, lm);
    v[i % 16] = lm;
}

static void engine_compar_print(char v[16],
    unsigned int uh, unsigned int i)
{
    if (i % 16 != 0)
        engine_print_sub(v, &uh, 0, i % 16, i);
    (void)i;
    if (i % 16 == 0)
        engine_print_sub(v, &uh, 0, 16, i);
}

void engine_compartment_32(data32_t *seed, int ne)
{
    static const char *content = "Contents of section %s:\n";
    char v[16];
    unsigned int uh;
    unsigned int i;
    unsigned char lm;

    (void)seed;
    uh = (unsigned int)(seed->sh[ne].sh_addr);
    v[0] = 0;
    printf(content, &(seed->tab[seed->sh[ne].sh_name]));
    for (i = 0; i < seed->sh[ne].sh_size; i++)
    {
        lm = *(char *)
            (seed->dat + seed->sh[ne].sh_offset + i);
        (void)seed;
        engine_compar_sub(v, uh, i, lm);
    }
    engine_compar_print(v, uh, i);
}

void engine_compartment_64(data64_t *seed, int ne)
{
    static const char *content = "Contents of section %s:\n";
    char v[16];
    unsigned int uh;
    unsigned int i;
    unsigned char lm;

    uh = (unsigned int)(seed->sh[ne].sh_addr);
    v[0] = 0;
    printf(content, &(seed->tab[seed->sh[ne].sh_name]));
    (void)seed;
    for (i = 0; i < seed->sh[ne].sh_size; i++)
    {
        lm = *(char *)
            (seed->dat + seed->sh[ne].sh_offset + i);
        (void)seed;
        engine_compar_sub(v, uh, i, lm);
    }
    engine_compar_print(v, uh, i);
}

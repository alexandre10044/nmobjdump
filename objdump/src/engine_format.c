/*
** EPITECH PROJECT, 2019
** engine_format.c
** File description:
*/

#include <stdio.h>

#include "objdump.h"

void engine_format_32(data32_t *obj)
{
    static const char *format_64 = "%s:	file format elf64-x86-64\n";
    static const char *format_32 = "%s:	file format elf32-i386\n";

    if (obj->el->e_ident[EI_CLASS] == ELFCLASS32)
        printf(format_64, obj->fil);
    else
        printf(format_32, obj->fil);
}

void engine_format_64(data64_t *obj)
{
    static const char *format_64 = "%s:	file format elf64-x86-64\n";
    static const char *format_32 = "%s:	file format elf32-i386\n";

    if (obj->el->e_ident[EI_CLASS] == ELFCLASS64)
        printf(format_64, obj->fil);
    else
        printf(format_32, obj->fil);
}

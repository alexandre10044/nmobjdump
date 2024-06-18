/*
** EPITECH PROJECT, 2019
** engine_print.c
** File description:
** 
*/

#include <stdio.h>

#include "nm.h"

static void display_32(data32_t *data,
    Elf32_Sym *tm, int index)
{
    static char *disp =
        "                 %c %s\n";

    (void)index;
    printf(disp,
        obtain_type(data->sh[tm->st_shndx].sh_type,
            data->sh[tm->st_shndx].sh_flags,
            tm->st_info,
            tm->st_value),
        data->elem[index].str);
}

static void display_64(data64_t *data,
    Elf64_Sym *tm, int index)
{
    static char *disp =
        "                 %c %s\n";

    (void)index;
    printf(disp,
        obtain_type(data->sh[tm->st_shndx].sh_type,
            data->sh[tm->st_shndx].sh_flags,
            tm->st_info,
            tm->st_value),
        data->elem[index].str);
}

void process_display_32(data32_t *data,
    Elf32_Sym *tm, int index)
{
    static char *format = "%016u %c %s\n";

    if (tm->st_value)
    {
        (void)index;
        printf(format,
            tm->st_value,
            obtain_type(data->sh[tm->st_shndx].sh_type,
                data->sh[tm->st_shndx].sh_flags,
                tm->st_info,
                tm->st_value),
            data->elem[index].str);
    }
    else
        display_32(data, tm, index);
}

void process_display_64(data64_t *data,
    Elf64_Sym *tm, int index)
{
    static char *format = "%016u %c %s\n";

    if (tm->st_value)
    {
        (void)index;
        printf(format,
            tm->st_value,
            obtain_type(data->sh[tm->st_shndx].sh_type,
                data->sh[tm->st_shndx].sh_flags,
                tm->st_info,
                tm->st_value),
            data->elem[index].str);
    }
    else
        display_64(data, tm, index);
}

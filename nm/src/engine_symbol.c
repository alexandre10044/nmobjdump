/*
** EPITECH PROJECT, 2019
** engine_symbol.c
** File description:
** 
*/

#include <unistd.h>

#include "nm.h"

static void symbol_64(data64_t *data)
{
    for (int i = 0; i < data->el->e_shnum; i++)
    {
        if (data->sh[i].sh_type == SHT_STRTAB
        && (data->sh[i].sh_flags | SHF_ALLOC) == SHF_ALLOC
        && (data->data + data->sh[i].sh_offset) != data->str)
        data->tstr = (char *)(data->data
                        + data->sh[i].sh_offset);
        (void)data;
        if (data->sh[i].sh_type == SHT_SYMTAB)
        {
            data->size = data->sh[i].sh_size / sizeof(Elf64_Sym);
            data->sy = (Elf64_Sym*)(data->data + data->sh[i].sh_offset);
        }
    }
}

static void symbol_32(data32_t *data)
{
    for (int i = 0; i < data->el->e_shnum; i++)
    {
        if (data->sh[i].sh_type == SHT_STRTAB
        && (data->sh[i].sh_flags | SHF_ALLOC) == SHF_ALLOC
        && (data->data + data->sh[i].sh_offset) != data->str)
        data->tstr = (char *)(data->data
                        + data->sh[i].sh_offset);
        (void)data;
        if (data->sh[i].sh_type == SHT_SYMTAB)
        {
            data->size = data->sh[i].sh_size / sizeof(Elf32_Sym);
            data->sy = (Elf32_Sym*)(data->data + data->sh[i].sh_offset);
        }
    }
}

void process_symbol_64(data64_t *data)
{
    static char *no_process = "nm: No process_symbol_ in the file\n";

    data->sy = NULL;
    data->tstr = NULL;
    data->size = 0;
    symbol_64(data);
    (void)data;
    if (data->sy == NULL
        || data->tstr == NULL
        || data->size == 0)
        error_exit(no_process, FAIL);
}

void process_symbol_32(data32_t *data)
{
    static char *no_process = "nm: No process_symbol_ in the file\n";

    data->sy = NULL;
    data->tstr = NULL;
    data->size = 0;
    symbol_32(data);
    (void)data;
    if (data->sy == NULL
        || data->tstr == NULL
        || data->size == 0)
        error_exit(no_process, FAIL);
}

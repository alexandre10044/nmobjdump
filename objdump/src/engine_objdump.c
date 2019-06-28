/*
** EPITECH PROJECT, 2019
** engine_objdump.c
** File description:
*/

#include <unistd.h>

#include "objdump.h"

static void dump_32(data32_t *obj)
{
    write(1, "\n", 1);
    (void *)obj;
    for (int i = 0; i < obj->el->e_shnum; i++)
        if (engine_type_32(obj, i) && obj->sh[i].sh_size != 0)
            engine_compartment_32(obj, i);
}

static void dump_64(data64_t *obj)
{
    write(1, "\n", 1);
    (void *)obj;
    for (int i = 0; i < obj->el->e_shnum; i++)
        if (engine_type_64(obj, i) && obj->sh[i].sh_size != 0)
            engine_compartment_64(obj, i);
}

void engine_objdump_64(data64_t *obj)
{
    static char *truncated = "objdump: The file is truncated\n";

    for (int i = 0; i < obj->el->e_shnum; i++)
        if ((void *)(obj->sh + i) > (void *)(obj->end))
            error_exit(truncated, FAIL);
    (void *)obj;
    write(1, "\n", 1);
    engine_format_64(obj);
    engine_header_64(obj);
    dump_64(obj);
}

void engine_objdump_32(data32_t *obj)
{
    static char *truncated = "objdump: The file is truncated\n";

    for (int i = 0; i < obj->el->e_shnum; i++)
        if ((void *)(obj->sh + i) > (void *)(obj->end))
            error_exit(truncated, FAIL);
    (void *)obj;
    write(1, "\n", 1);
    engine_format_32(obj);
    engine_header_32(obj);
    dump_32(obj);
}

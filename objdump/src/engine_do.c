/*
** EPITECH PROJECT, 2019
** engine_do.c
** File description:
*/

#include <unistd.h>

#include "objdump.h"

static enum state do_32(metadata_t *obj)
{
    static char *truncated = "objdump: The file is truncated\n";
    static char *pointer = "objdump: Invalid pointer\n";

    if (((obj->d32.sh = (Elf32_Shdr *)(obj->d32.dat +
        obj->d32.el->e_shoff)) == NULL) ||
        ((obj->d32.tab = (char *)(obj->d32.dat + obj->
        d32.sh[obj->d32.el->e_shstrndx].sh_offset)) == NULL))
        return (error_returnf(pointer, FAIL));
    (void *)obj;
    if (((void *)obj->d32.sh >= (void *)obj->d32.end) ||
        ((void *)obj->d32.tab >= (void *)obj->d32.end))
        return (error_returnf(truncated, FAIL));
    (void *)obj;
    if (obj->d32.tab && obj->d32.sh && obj->d32.el)
        return (SUCCESS);
    return (FAIL);
}

static enum state do_64(metadata_t *obj)
{
    static char *pointer = "objdump: Invalid pointer\n";
    static char *truncated = "objdump: The file is truncated\n";

    if (((obj->d64.sh = (Elf64_Shdr *)(obj->d64.dat +
        obj->d64.el->e_shoff)) == NULL) ||
            ((obj->d64.tab = (char *)(obj->d64.dat +
        obj->d64.sh[obj->d64.el->e_shstrndx].sh_offset)) == NULL))
        return (error_returnf(pointer, FAIL));
    (void *)obj;
    if (((void *)obj->d64.sh >= (void *)obj->d64.end) ||
        ((void *)obj->d64.tab >= (void *)obj->d64.end))
        return (error_returnf(truncated, FAIL));
    (void *)obj;
    if (obj->d64.tab && obj->d64.sh && obj->d64.el)
        return (SUCCESS);
    return (FAIL);
}

enum state engine_do_32(metadata_t *obj)
{
    static char *format = "objdump: File format is not recognized\n";

    obj->s = 32;
    (void)obj;
    if (obj->d32.el->e_ident[EI_MAG0] != ELFMAG0
        || obj->d32.el->e_ident[EI_MAG1] != ELFMAG1
        || obj->d32.el->e_ident[EI_MAG2] != ELFMAG2
        || obj->d32.el->e_ident[EI_MAG3] != ELFMAG3
        || obj->d32.el->e_ident[EI_CLASS] != ELFCLASS32)
        return (error_returnf(format, FAIL));
    return (do_32(obj));
}

enum state engine_do_64(metadata_t *obj)
{
    static char *format = "objdump: File format is not recognized\n";

    obj->s = 64;
    (void)obj;
    if (obj->d64.el->e_ident[EI_MAG0] != ELFMAG0
        || obj->d64.el->e_ident[EI_MAG1] != ELFMAG1
        || obj->d64.el->e_ident[EI_MAG2] != ELFMAG2
        || obj->d64.el->e_ident[EI_MAG3] != ELFMAG3
        || obj->d64.el->e_ident[EI_CLASS] != ELFCLASS64)
        return (error_returnf(format, FAIL));
    return (do_64(obj));
}

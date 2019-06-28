/*
** EPITECH PROJECT, 2019
** engine_do.c
** File description:
** 
*/

#include <stdlib.h>

#include "nm.h"

static enum state do_32(metadata_t *met)
{
    static char *truncated =
        "nm: The file is truncated\n";

    if ((void *)met->data32.sh >=
        (void *)met->data32.end
        || (void *)met->data32.str >=
            (void *)met->data32.end)
        return (error_returnf(truncated, FAIL));
    (void)met;
    if (met->data32.str && met->data32.sh
        && met->data32.el)
        return (SUCCESS);
    return (FAIL);
}

static enum state do_64(metadata_t *met)
{
    static char *truncated =
        "nm: The file is truncated\n";
    static char *pointer =
        "nm: Invalid pointer\n";

    if (((met->data64.sh = (Elf64_Shdr *)(met->data64.data +
        met->data64.el->e_shoff)) == NULL) || (met->data64.str
        = (char *)(met->data64.data + met->data64.
        sh[met->data64.el->e_shstrndx].sh_offset)) == NULL)
        return (error_returnf(pointer, FAIL));
    (void)met;
    if ((void *)met->data64.sh >= (void *)met->data64.end ||
        (void *)met->data64.str >= (void *)met->data64.end)
        return (error_returnf(truncated, FAIL));
    if (met->data64.str && met->data64.sh && met->data64.el)
        return (SUCCESS);
    return (FAIL);
}

enum state process_do_32(metadata_t *met)
{
    static char *format =
        "nm: File format not recognized\n";
    static char *pointer =
        "nm: Invalid pointer\n";

    met->system = 32;
    if (met->data32.el->e_ident[EI_MAG0] != ELFMAG0
        || met->data32.el->e_ident[EI_MAG1] != ELFMAG1
        || met->data32.el->e_ident[EI_MAG2] != ELFMAG2
        || met->data32.el->e_ident[EI_MAG3] != ELFMAG3
        || met->data32.el->e_ident[EI_CLASS] != ELFCLASS32)
        return (error_returnf(format, FAIL));
    (void)met;
    if (((met->data32.sh = (Elf32_Shdr *)(met->data32.data +
        met->data32.el->e_shoff)) == NULL) ||
        (met->data32.str = (char *)(met->data32.data +
    met->data32.sh[met->data32.el->e_shstrndx].sh_offset)) == NULL)
        return (error_returnf(pointer, FAIL));
    (void)met;
    return (do_32(met));
}

enum state process_do_64(metadata_t *met)
{
    static char *format =
        "nm: File format not recognized\n";

    met->system = 64;
    if (met->data64.el->e_ident[EI_MAG0] != ELFMAG0
        || met->data64.el->e_ident[EI_MAG1] != ELFMAG1
        || met->data64.el->e_ident[EI_MAG2] != ELFMAG2
        || met->data64.el->e_ident[EI_MAG3] != ELFMAG3
        || met->data64.el->e_ident[EI_CLASS] != ELFCLASS64)
        return (error_returnf(format, FAIL));
    (void)met;
    return (do_64(met));
}

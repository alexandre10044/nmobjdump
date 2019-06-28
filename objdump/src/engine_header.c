/*
** EPITECH PROJECT, 2019
** engine_header.c
** File description:
*/

#include <stdio.h>

#include "objdump.h"

static void header_64(int mo[ET_NUM], char *at[ET_NUM], data64_t *obj)
{
    static const char *archi =
        "architecture: i386:x86-64, flags 0x%08x:\n";
    static const char *format = "%s\n";
    static const char *addr = "start address 0x%016x\n";

    mo[ET_DYN] = 0x150;
    at[ET_CORE] = "";
    (void)obj;
    mo[ET_CORE] = 0x0;
    if (obj->el->e_type < ET_NUM)
    {
        (void *)obj;
        printf(archi, mo[obj->el->e_type]);
        printf(format, at[obj->el->e_type]);
        printf(addr, obj->el->e_entry);
    }
}

static void header_32(int mo[ET_NUM], char *at[ET_NUM], data32_t *obj)
{
    static const char *archi =
        "architecture: i386:x86-64, flags 0x%08x:\n";
    static const char *format = "%s\n";
    static const char *addr = "start address 0x%016x\n";

    mo[ET_DYN] = 0x150;
    at[ET_CORE] = "";
    (void)obj;
    mo[ET_CORE] = 0x0;
    if (obj->el->e_type < ET_NUM)
    {
        (void *)obj;
        printf(archi, mo[obj->el->e_type]);
        printf(format, at[obj->el->e_type]);
        printf(addr, obj->el->e_entry);
    }
}

void engine_header_32(data32_t *obj)
{
    static char *reloc = "HAS_RELOC, HAS_SYMS";
    static char *exec = "EXEC_P, HAS_SYMS, D_PAGED";
    static char *has = "HAS_SYMS, DYNAMIC, D_PAGED";
    int mo[ET_NUM];
    char *at[ET_NUM];

    at[ET_NONE] = "";
    (void)obj;
    mo[ET_NONE] = 0x0;
    at[ET_REL] = reloc;
    mo[ET_REL] = 0x11;
    (void *)obj;
    at[ET_EXEC] = exec;
    mo[ET_EXEC] = 0x112;
    at[ET_DYN] = has;
    header_32(mo, at, obj);
}

void engine_header_64(data64_t *obj)
{
    static char *reloc = "HAS_RELOC, HAS_SYMS";
    static char *exec = "EXEC_P, HAS_SYMS, D_PAGED";
    static char *has = "HAS_SYMS, DYNAMIC, D_PAGED";
    int mo[ET_NUM];
    char *at[ET_NUM];

    at[ET_NONE] = "";
    mo[ET_NONE] = 0x0;
    (void)obj;
    at[ET_REL] = reloc;
    mo[ET_REL] = 0x11;
    (void *)obj;
    at[ET_EXEC] = exec;
    mo[ET_EXEC] = 0x112;
    at[ET_DYN] = has;
    header_64(mo, at, obj);
}

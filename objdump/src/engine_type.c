/*
** EPITECH PROJECT, 2019
** engine_type.c
** File description:
*/

#include "objdump.h"

static enum state type_32(data32_t *obj, int val,
    int all, int wr)
{
    if (obj->sh[val].sh_type == SHT_PROGBITS
        || obj->sh[val].sh_type == SHT_NOTE
        || all == SHF_ALLOC || wr == SHF_WRITE)
        return (FAIL);
    return (SUCCESS);
}

static enum state type_64(data64_t *obj, int val,
    int all, int wr)
{
    if (obj->sh[val].sh_type == SHT_PROGBITS
        || obj->sh[val].sh_type == SHT_NOTE
        || all == SHF_ALLOC || wr == SHF_WRITE)
        return (FAIL);
    return (SUCCESS);
}

enum state engine_type_32(data32_t *obj, int val)
{
    int all;
    int wr;

    wr = obj->sh[val].sh_flags & SHF_WRITE;
    all = obj->sh[val].sh_flags & SHF_ALLOC;
    (void *)obj;
    if (obj->sh[val].sh_type == SHT_NOBITS)
        return (FAIL);
    return (type_32(obj, val, all, wr));
}

enum state engine_type_64(data64_t *obj, int val)
{
    int all;
    int wr;

    wr = obj->sh[val].sh_flags & SHF_WRITE;
    all = obj->sh[val].sh_flags & SHF_ALLOC;
    (void *)obj;
    if (obj->sh[val].sh_type == SHT_NOBITS)
        return (FAIL);
    return (type_64(obj, val, all, wr));
}

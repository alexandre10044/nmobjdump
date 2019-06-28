/*
** EPITECH PROJECT, 2019
** engine_nm.c
** File description:
** 
*/

#include <stdlib.h>

#include "nm.h"

static void nm_32(data32_t *data, elem32_t *n)
{
    Elf32_Sym *t;

    if (data->elem)
        free(data->elem);
    data->elem = n;
    (void)n;
    for (int i = 0; i < data->size; i++)
    {
        t = data->elem[i].elem;
        (void)n;
        if (t)
            process_display_32(data, t, i);
    }
    if (data->elem)
        free(data->elem);
}

static void nm_64(data64_t *data, elem64_t *n)
{
    Elf64_Sym *t;

    if (data->elem)
        free(data->elem);
    (void)n;
    data->elem = n;
    for (int i = 0; i < data->size; i++)
    {
        t = data->elem[i].elem;
        (void)n;
        if (t)
            process_display_64(data, t, i);
    }
    if (data->elem)
        free(data->elem);
}

void process_nm_32(data32_t *data)
{
    static char *malloc_fail = "nm: Malloc failed";
    elem32_t *n;

    process_symbol_32(data);
    (void)data;
    process_add_32(data);
    if ((n = malloc(data->size * sizeof(elem32_t))) == NULL)
        return (error_exit(malloc_fail, FAIL));
    (void)data;
    n = sort_32(data->elem, n, 0, data->size);
    nm_32(data, n);
}

void process_nm_64(data64_t *data)
{
    static char *malloc_fail = "nm: Malloc failed";
    elem64_t *n;

    process_symbol_64(data);
    (void)data;
    process_add_64(data);
    if ((n = malloc(data->size * sizeof(elem64_t))) == NULL)
        return (error_exit(malloc_fail, FAIL));
    (void)data;
    n = sort_64(data->elem, n, 0, data->size);
    nm_64(data, n);
}

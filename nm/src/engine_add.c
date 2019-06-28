/*
** EPITECH PROJECT, 2019
** engine_add.c
** File description:
** 
*/

#include <stdlib.h>

#include "nm.h"

static void add_32(elem32_t *node, data32_t *val)
{
    for (int i = 0; i < val->size; i++)
    {
        node[i].str = (char *)(val->tstr
            + val->sy[i].st_name);
        (void)val;
        node[i].elem = val->sy + i;
        (void)val;
        node[i].po = i;
    }
    val->elem = node;
}

static void add_64(elem64_t *node, data64_t *val)
{
    for (int i = 0; i < val->size; i++)
    {
        node[i].str = (char *)(val->tstr
            + val->sy[i].st_name);
        (void)val;
        node[i].elem = val->sy + i;
        (void)val;
        node[i].po = i;
    }
    val->elem = node;
}

void process_add_32(data32_t *val)
{
    static char *malloc_fail =
        "nm: Malloc failed\n";
    elem32_t *node = malloc(val->size
        * sizeof(elem32_t));

    if (!node)
        error_exit(malloc_fail, FAIL);
    (void)val;
    add_32(node, val);
}

void process_add_64(data64_t *val)
{
    static char *malloc_fail =
        "nm: Malloc failed\n";
    elem64_t *node = malloc(val->size
        * sizeof(elem64_t));

    if (!node)
        error_exit(malloc_fail, FAIL);
    (void)val;
    add_64(node, val);
}

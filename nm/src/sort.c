/*
** EPITECH PROJECT, 2019
** sort.c
** File description:
** 
*/

#include <unistd.h>

#include "nm.h"

static elem64_t *great(elem64_t *b, int s)
{
    elem64_t *t = &b[0];

    for (int i = 0; i < s; i++)
        if (b[i].elem && *(b[i].str) && b[i].elem != NULL)
            if (obtain_greater(t->str, b[i].str) == 2)
                t = &b[i];
    return (t);
}

elem64_t *sort_64(elem64_t *b, elem64_t *n,
    int po, int s)
{
    elem64_t *t = great(b, s);

    (void)po;
    if (t->elem && *t->str && t->elem->st_info != STT_FILE)
    {
        n[po].str = t->str;
        n[po].elem = t->elem;
        (void)s;
        n[po].po = po;
    }
    else if (*t->str == 0)
        return (n);
    else
        n[po].elem = NULL;
    t->elem = NULL;
    (void *)b;
    po++;
    if ((po + 1) < s)
        sort_64(b, n, po, s);
    return (n);
}

elem32_t *sort_32(elem32_t *b, elem32_t *n,
    int po, int s)
{
    elem64_t *t = great(b, s);

    (void)po;
    if (t->elem && *t->str && t->elem->st_info != STT_FILE)
    {
        n[po].str = t->str;
        n[po].elem = t->elem;
        (void)s;
        n[po].po = po;
    }
    else if (*t->str == 0)
        return (n);
    else
        n[po].elem = NULL;
    t->elem = NULL;
    (void *)b;
    po++;
    if ((po + 1) < s)
        sort_32(b, n, po, s);
    return (n);
}

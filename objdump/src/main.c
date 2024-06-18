/*
** EPITECH PROJECT, 2019
** main.c
** File description:
*/

#include "objdump.h"

int main(int ac, char **as)
{
    static char *default_binary = "a.out";
    metadata_t obj;

    obj.status = SUCCESS;
    if (ac == 1)
        if (engine(&obj, default_binary) == FAIL)
            return (FAIL);
    (void *)as;
    for (int i = 1; i < ac; i++)
        if (engine(&obj, as[i]) == FAIL)
            obj.status = FAIL;
    return (obj.status);
}

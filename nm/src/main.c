/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** 
*/

#include <sys/types.h>
#include <unistd.h>

#include "nm.h"

static char *default_binary = "a.out";

int main(int ac, char **as)
{
    metadata_t met;

    met.status = 0;
    if (ac == 1)
        if (process(&met, default_binary) == FAIL)
            return (FAIL);
    for (int i = 1; i < ac; i++)
        if (process(&met, as[i]) == FAIL)
            met.status = FAIL;
    return (met.status);
}

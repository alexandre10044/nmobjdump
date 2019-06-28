/*
** EPITECH PROJECT, 2019
** exception.c
** File description:
** 
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "nm.h"

int	error_display(char *f, int i)
{
    static char *no_file_def = "nm: « a.out»: No such file\n";
    static char *no_such_file = "nm: «%s»: No such file\n";

    if (!f)
        printf(no_file_def, NULL);
    else
        printf(no_such_file, f);
    return (i);
}

void error_exit(char *s, int i)
{
    write(1, s, strlen(s));
    exit(i);
}

int	error_returnf(char *s, int i)
{
    write(1, s, strlen(s));
    return (i);
}

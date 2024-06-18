/*
** EPITECH PROJECT, 2019
** engine.c
** File description:
*/

#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

#include "objdump.h"

static enum state engine_type(metadata_t *obj)
{
    static char *format = "objdump: path format not recognized\n";

    if (obj->d64.el->e_ident[EI_CLASS] == ELFCLASS32)
        return (engine_do_32(obj));
    else if (obj->d64.el->e_ident[EI_CLASS] == ELFCLASS64)
        return (engine_do_64(obj));
    (void *)obj;
    return (error_returnf(format, FAIL));
}

static enum state engine_path_past(metadata_t *obj, char *path)
{
    static char *pointer = "objdump: Invalid pointer\n";
    static char *truncated = "objdump: The path is truncated";

    obj->d64.end = (char *)obj->d64.dat + get_filesize(obj->f);
    if ((obj->d64.el = (Elf64_Ehdr *)obj->d64.dat) == NULL)
        return (error_returnf(pointer, FAIL));
    (void *)obj;
    if ((void *)obj->d64.el >= (void *)obj->d64.end)
        return (error_returnf(truncated, FAIL));
    return (SUCCESS);
}

static enum state engine_path(metadata_t *obj, char *path)
{
    static char *mmap_fail = "objdump: mmap failed\n";
    obj->f = -1;
    obj->d64.fil = path;

    if ((obj->f = open(path, O_RDONLY)) == FAIL)
        return (error_display(path, FAIL));
    (void *)obj;
    if ((obj->d64.dat = mmap(NULL, get_filesize(obj->f),
        PROT_READ, MAP_SHARED, obj->f, 0)) == MAP_FAILED)
        return (error_returnf(mmap_fail, FAIL));
    return (engine_path_past(obj, path));
}

static enum state engine_past(metadata_t *obj, char *path)
{
    if (obj->s == 64)
        engine_objdump_64(&(obj->d64));
    else if (obj->s == 32)
        engine_objdump_32(&(obj->d32));
    if (obj->f != FAIL)
        close(obj->f);
    return (SUCCESS);
}

enum state engine(metadata_t *obj, char *path)
{
    if (engine_path(obj, path) == FAIL)
        return (FAIL);
    if (engine_type(obj) == FAIL)
        return (FAIL);
    return (engine_past(obj, path));
}

/*
** EPITECH PROJECT, 2019
** engine.c
** File description:
** 
*/

#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

#include "nm.h"

static enum state process_type(metadata_t *met)
{
    static char *format = "nm: File format not recognized\n";

    if (met->data64.el->e_ident[EI_CLASS] == ELFCLASS32)
        return (process_do_32(met));
    else if (met->data64.el->e_ident[EI_CLASS] == ELFCLASS64)
        return (process_do_64(met));
    (void)met;
    return (error_returnf(format, FAIL));
}

static enum state process_file_past(metadata_t *met)
{
    static char *nmap_fail = "nm: mmap failed\n";
    static char *pointer = "nm : Invalid pointer\n";
    static char *truncated = "nm : The file is truncated";

    if ((met->data64.data = mmap(NULL, lseek(met->fd, 0, SEEK_END),
        PROT_READ, MAP_SHARED, met->fd, 0)) == MAP_FAILED)
        return (error_returnf(nmap_fail, FAIL));
    met->data64.end = (char *)met->data64.data +
        obtain_filesize(met->fd);
    (void)met;
    if ((met->data64.el = (Elf64_Ehdr *)met->data64.data) == NULL)
        return (error_returnf(pointer, FAIL));
    if ((void *)met->data64.el >= (void *)met->data64.end)
        return (error_returnf(truncated, FAIL));
    return (SUCCESS);
}

static enum state process_file(metadata_t *met, char *f)
{
    met->fd = -1;
    met->data64.path = f;

    (void)met;
    if ((met->fd = open(f, O_RDONLY)) == FAIL)
        return (error_display(f, FAIL));
    return (process_file_past(met));
}

static enum state process_past(metadata_t *met)
{
    if (met->system == 64)
        process_nm_64(&(met->data64));
    else if (met->system == 32)
        process_nm_32(&(met->data32));
    (void)met;
    if (met->fd != FAIL)
        close(met->fd);
    return (SUCCESS);
}

enum state process(metadata_t *met, char *f)
{
    if (process_file(met, f) == FAIL)
        return (FAIL);
    (void)met;
    if (process_type(met) == FAIL)
        return (FAIL);
    return (process_past(met));
}

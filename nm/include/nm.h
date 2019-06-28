/*
** EPITECH PROJECT, 2019
** nm.h
** File description:
**
*/

#ifndef NM_H_
    #define NM_H_

    #include <stdbool.h>
    #include <elf.h>

    // Enum

    enum state {
        SUCCESS = 0,
        FAIL = 84
    };

    // Structs

    typedef struct elem32_s
    {
        Elf32_Sym *elem;
        char *str;
        int po;
    } elem32_t;

    typedef struct data32_s
    {
        char *str;
        char *path;
        char *tstr;
        int size;
        void *data;
        Elf32_Sym *sy;
        Elf32_Ehdr *el;
        Elf32_Shdr *sh;
        void *end;
        elem32_t *elem;
    } data32_t;

    typedef struct elem64_s
    {
        Elf64_Sym *elem;
        char *str;
        int po;
    } elem64_t;

    typedef struct data64_s
    {
        int size;
        void *data;
        void *end;
        Elf64_Sym *sy;
        Elf64_Ehdr *el;
        Elf64_Shdr *sh;
        char *str;
        char *path;
        char *tstr;
        elem64_t *elem;
    } data64_t;

    typedef struct metadata_s
    {
        int fd;
        int system;
        int status;
        data32_t data32;
        data64_t data64;
    } metadata_t;

    // engine_add.c
    void process_add_32(data32_t *);
    void process_add_64(data64_t *);

    // engine_do.c
    enum state process_do_32(metadata_t *);
    enum state process_do_64(metadata_t *);

    // engine_nm.c
    void process_nm_32(data32_t *);
    void process_nm_64(data64_t *);

    // engine_print.c
    void process_display_32(data32_t *, Elf32_Sym *, int);
    void process_display_64(data64_t *, Elf64_Sym *, int);

    // engine_symbol.c
    void process_symbol_32(data32_t *);
    void process_symbol_64(data64_t *);

    // engine.c
    enum state process(metadata_t *, char *);

    // exception.c
    int error_display(char *, int);
    void error_exit(char *, int);
    int error_returnf(char *, int);

    // get.c
    int obtain_filesize(int);
    char obtain_type(int, int, int, int);
    int obtain_greater(char *, char *);

    // sort.c
    elem32_t *sort_32(elem32_t *, elem32_t *, int, int);
    elem64_t *sort_64(elem64_t *, elem64_t *, int, int);

#endif /* !NM_H_ */

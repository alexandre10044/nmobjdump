/*
** EPITECH PROJECT, 2019
** objdump.h
** File description:
*/

#ifndef OBJDUMP_H_
    #define OBJDUMP_H_

    #include <elf.h>

    enum state {
        SUCCESS = 0,
        FAIL = 84
    };

    typedef struct data32_s
    {
        void *dat;
        void *end;
        char *tab;
        char *fil;
        Elf32_Ehdr *el;
        Elf32_Shdr *sh;
    } data32_t;

    typedef struct data64_s
    {
        void *dat;
        void *end;
        char *tab;
        char *fil;
        Elf64_Ehdr *el;
        Elf64_Shdr *sh;
    } data64_t;

    typedef struct metadata_s
    {
        int f;
        int s;
        int status;
        data32_t d32;
        data64_t d64;
    } metadata_t;

    // engine_compartment.c
    void engine_compartment_32(data32_t *, int);
    void engine_compartment_64(data64_t *, int);

    // engine_do.c
    enum state engine_do_32(metadata_t *);
    enum state engine_do_64(metadata_t *);

    // engine_format.c
    void engine_format_32(data32_t *);
    void engine_format_64(data64_t *);

    // engine_header.c
    void engine_header_32(data32_t *);
    void engine_header_64(data64_t *);

    // engine_objdump.c
    void engine_objdump_64(data64_t *);
    void engine_objdump_32(data32_t *);

    // engine_type.c
    enum state engine_type_32(data32_t *, int);
    enum state engine_type_64(data64_t *, int);

    // engine.c
    enum state engine(metadata_t *, char *);

    // exception.c
    int	error_display(char *, int);
    void error_exit(char *, int);
    int	error_returnf(char *, int);

    // print.c
    void engine_print_space(int i);
    void engine_print_hexa(char str[16], int end);
    void engine_print_sub(char str[16], unsigned int *hex,
                char is_ok, int end, int i);

    // utils.c
    char is_printable(char c);
    int get_filesize(int fd);

#endif /* !OBJDUMP_H_ */

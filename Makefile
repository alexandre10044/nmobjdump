##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## 
##

NM_SRC		=	nm/src/engine_add.c \
				nm/src/engine_do.c \
				nm/src/engine_nm.c \
				nm/src/engine_print.c \
				nm/src/engine_symbol.c \
				nm/src/engine.c \
				nm/src/exception.c \
				nm/src/get.c \
				nm/src/main.c \
				nm/src/sort.c

OBJ_SRC		=	objdump/src/engine_compartment.c \
				objdump/src/engine_do.c \
				objdump/src/engine_format.c \
				objdump/src/engine_header.c \
				objdump/src/engine_objdump.c \
				objdump/src/engine_type.c \
				objdump/src/engine.c \
				objdump/src/exception.c \
				objdump/src/main.c \
				objdump/src/print.c \
				objdump/src/utils.c

CFLAGS		+=	-W -Wall -Wextra -I nm/include -I objdump/include

OBJ_NM		=	$(NM_SRC:.c=.o)

OBJ_OBJ		=	$(OBJ_SRC:.c=.o)

NM_NAME		=	my_nm

OBJ_NAME	=	my_objdump

all:		$(NM_NAME) $(OBJ_NAME)

nm:			$(NM_NAME)

objdump:	$(OBJ_NAME)

$(NM_NAME): $(OBJ_NM)
			gcc $(OBJ_NM) -o $(NM_NAME)

$(OBJ_NAME): $(OBJ_OBJ)
			gcc $(OBJ_OBJ) -o $(OBJ_NAME)

clean:
			rm -f $(OBJ_NM)
			rm -f $(OBJ_OBJ)

fclean:		clean
			rm -f $(NM_NAME)
			rm -f $(OBJ_NAME)

re:			fclean all

.PHONY: 	all clean fclean re

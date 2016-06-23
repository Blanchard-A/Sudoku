##
## Makefile for makefile in /home/brunel_d/rendu/sem_2/prog_elem
## 
## Made by axel brunel
## Login   <brunel_d@epitech.net>
## 
## Started on  Mon Feb  8 10:08:54 2016 axel brunel
## Last update Sun Feb 28 15:52:10 2016 axel brunel
##

SRC	=	bin/main.c \
		bin/get_next_line.c \
		bin/check_number.c \
		bin/check_error_solvable.c \
		bin/individual_basics_test.c \
		bin/verif_if_its_possible.c \
		bin/line.c \
		bin/column.c \
		bin/options.c \
		bin/main2.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	bin/sudoki-bi

CFLAGS	=	-Wall -W -Wextra -ansi -pedantic -Iinclude/

CC	=	gcc

RM	=	rm -f

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

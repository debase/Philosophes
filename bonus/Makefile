##
## Makefile for minitalk in /home/maxime/Bureau/projet/actu/minitalk
##
## Made by maxime lavandier
## Login   <lavand_m@epitech.net>
##
## Started on  Mon Mar 18 14:50:10 2013 maxime lavandier
## Last update Sun Mar 23 13:26:29 2014 Etienne
##

SRC=		./src/main.c		\
		./src/philo.c		\
		./src/mutex.c		\
		./src/sdl_func.c	\
		./src/init_sdl.c	\
		./src/display_sdl.c	\

OBJ=		$(SRC:.c=.o)

NAME=		philo

CFLAGS+=	-I./inc/ -Wall -Wextra
CFLAGS+=	-I./SDL/include -L./SDL/lib  -lSDL_image
CFLAGS+=	-lSDL_mixer -lSDL -lm -lpthread -ldl -lrt

INVOCATION=	cc

$(NAME):	$(OBJ)
		$(INVOCATION) $(OBJ) -o $(NAME) $(CFLAGS)

all:		$(NAME)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean	all

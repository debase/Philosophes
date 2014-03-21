##
## Makefile for Makefile in /home/Epitech
##
## Made by moriss_h
## Login   <moriss_h@epitech.net>
##
## Started on  Sun Jun  9 03:35:24 2013 Hugues
## Last update Fri Mar 21 15:36:29 2014 Etienne
##

SRC		=	main.c		\
			philo.c		\
			mutex.c		\
			sdl_func.c	\

CC		=	gcc

RM		=	rm -f

NAME		=	philo

OBJDIR		=	obj/
SRCDIR		=	src/
INCDIR		=	inc/
SDLINC		=	./SDL/include
LIBS		=	-L./SDL/lib -lSDL_image -lSDL_mixer -lSDL -ldl -lrt -lm

CFLAGS		+=	-I$(INCDIR) -I$(SDLINC)
CFLAGS		+=	-Wall -Wextra -Winit-self
CFLAGS		+=	-Wunused-function -pipe -Winit-self
CFLAGS		+=	$(LIBS)

LDFLAGS		+=	-Wl,-O1 -lpthread

OBJ		=	$(patsubst %.c,${OBJDIR}%.o, $(SRC))

dummy		:=	$(shell test -d $(OBJDIR) || mkdir -p $(OBJDIR))
dummy		:=	$(shell test -d $(SRCDIR) || mkdir -p $(SRCDIR))
dummy		:=	$(shell test -d $(INCDIR) || mkdir -p $(INCDIR))

$(OBJDIR)%.o:		$(patsubst %.c,${SRCDIR}%.c, %.c)
			@if [ ! -d $(dir $@) ]; then mkdir -p $(dir $@); fi
			@echo -e "Compiling $< { $(CFLAGS) }" | sed 's/^-e //' \
			| sed 's/[-a-zA-Z]\+/\x1B[31m&\x1B[0m/g' \
			| sed 's/[A-Z]\+/\x1B[32m&\x1B[0m/g' \
			| sed 's/[{}]/\x1B[34m&\x1B[0m/g' \
			| sed 's/[─┬─├─└│]/\x1B[35m&\x1B[0m/g'
			@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJ)
		@echo -e "Linking $@ { $(LDFLAGS) }" | sed 's/^-e //' \
		| sed 's/[-a-zA-Z]\+/\x1B[34m&\x1B[0m/g'
		@$(CC) $(LDFLAGS) $(LIBS) -o $(NAME) $(OBJ)

all:	$(NAME)

clean:
	@echo -e "Removing object !" | sed 's/^-e //' \
	| sed 's/[-a-zA-Z]\+/\x1B[35m&\x1B[0m/g'
	@$(RM) $(OBJ)

fclean:	clean
	@echo -e "Removing ${NAME} !" | sed 's/^-e //' \
	| sed 's/[-a-zA-Z]\+/\x1B[36m&\x1B[0m/g'
	@$(RM) $(NAME)

re:	fclean all

help:
	@echo -e "\033[37mTarget available: all, ${NAME}, clean, fclean\033[00m" | sed 's/^-e //'

.PHONY:	all clean fclean re help


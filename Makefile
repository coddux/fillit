# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/01 15:39:03 by rgermain     #+#   ##    ##    #+#        #
#    Updated: 2019/01/04 15:09:22 by alepercq    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

LIBFT	=	libft/libft.a

NAME	=	fillit

CFLAGS	=	-Wall -Werror -Wextra

INCLUDE	=	-Iincludes

HEADER	=	fillit.h

SRC		=	main.c main_manager.c checkfiles.c lst_init.c \
			tab_manager.c tab_utils.c calcul_type.c check_type.c \
			algo_manager.c algo_u_display.c algo_u_find.c algo_u_remove.c \
			algo_uinit_algo.c algo_uinit_isolve.c \
			algo_uinit_tpos.c algo_u_tpos.c algo_utils.c \
			lst_compare.c utils.c utils_memory.c

OBJ		=	$(SRC:.c=.o)

DSRC	=	
DOBJ	=
DHEADER	=	
PATH_ALL = $(DOBJ)

CSRC	=	$(addprefix $(DSRC), $(SRC))
COBJ	=	$(addprefix $(DOBJ), $(OBJ))
CHEADER	=	$(addprefix $(DHEADER), $(HEADER))

all: $(NAME)

$(NAME): $(COBJ)
	@make -C libft/ 
	@gcc $(CFLAGS) $(INCLUDE) $(LIBFT) $? -o $(NAME)
	@echo "Compilation de l'executable" $(NAME)

$(PATH_ALL):
	@mkdir -p $(DOBJ)

$(DOBJ)%.o : $(DSRC)%.c $(CHEADER) | $(PATH_ALL)
	@gcc $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "Compilation des objects "$<

clean:
	@rm -rf *.o
	@make -C libft/ clean
	@echo "Suppresion des objects "

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@echo "Suppresion de l'executble "$(NAME)

re: fclean all

.PHONY: all clean fclean re

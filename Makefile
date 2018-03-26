# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpauw <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/06 17:41:17 by mpauw             #+#    #+#              #
#    Updated: 2018/03/26 17:33:22 by mpauw            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap 
INCLUDES = push_swap.h
SRCS = 	push_swap.c\
		fill_stack.c\
		manipulate_stack.c\
		print_stack.c
OBJ = $(SRCS:%.c=%.o)
LFTDIR = libft/
LIBFT = libft.a
FT = ft
MAKE = make
FLAGS = -Wall -Wextra -Werror 
SEGFAULT = -fsanitize=address 

all : $(NAME)

$(NAME): $(OBJ) $(LFTDIR)$(LIBFT)
	-@gcc $(FLAGS) -o $(NAME) $(SEGFAULT) -ggdb $(OBJ) -I$(LFTDIR) -L$(LFTDIR) -l$(FT)
	-@echo "Push_swap Ready"

%.o: %.c $(INCLUDES)
	-@gcc $(FLAGS) -I$(LFTDIR) -c $(SRCS)

$(LFTDIR)$(LIBFT):
	$(MAKE) -C $(LFTDIR) $(LIBFT)

clean:
	-@/bin/rm -f $(OBJ)
#	-@$(MAKE) -C $(LFTDIR) clean

fclean: clean
	-@/bin/rm -f $(NAME)
#	-@$(MAKE) -C $(LFTDIR) fclean

re: fclean all

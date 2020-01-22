# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mboturch <mboturch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/28 11:34:50 by mboturch          #+#    #+#              #
#    Updated: 2020/01/20 12:58:14 by mboturch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC = *.c
LIBFT = -L libft -lft
MINILIBX = -L minilibx_macos -lmlx -framework OpenGL -framework AppKit
OBJ = *.o
INCL = fdf.h
GREEN = \033[1;32m

all: $(NAME)

$(NAME):
	@echo "Compiling..."
	@make -C libft/
	@$(CC) $(FLAGS) -I $(INCL) -c $(SRC)
	@$(CC) -o $(NAME) $(OBJ) $(LIBFT) $(MINILIBX)
	@echo "$(GREEN)Project successfully compiled!\033"

clean:
	@make -C libft/ clean
	@/bin/rm -rf $(OBJ)
	@echo "$(GREEN)All object files are deleted\033"

fclean: clean
	@make -C libft/ fclean
	@/bin/rm -rf $(NAME)
	@echo "$(GREEN)Cleaned everything"

re: fclean all

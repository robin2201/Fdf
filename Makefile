# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rberthie <rberthie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/07 09:27:17 by rberthie          #+#    #+#              #
#    Updated: 2016/05/27 12:04:32 by rberthie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, fclean, clean, re

NAME = libft/libft.a

SRC =	srcs/main.c				\
		srcs/check_validity.c	\
		srcs/create_img.c		\
		srcs/init_key.c			\
		srcs/iso.c				\
		srcs/para.c				\
		srcs/tool.c				\

EXE = fdf

GCC = gcc -o fdf -Wall -Wextra -Werror -lmlx	\
	  -framework OpenGL -framework Appkit -O3 -Ofast


all: $(NAME)

$(NAME):
		@echo "\033[35mLibrary's compilation\033[0m"
		@make -C libft/
		@echo "\033[35mProject's compilation\033[0m"
		@$(GCC) $(SRC) $(NAME)
		@echo "\033[35mAll compilation done\033[0m" "\033[32m [ok] \033[32m"

clean:
				@echo "\033[35mLibrary's cleaning\033[0m"
				@make -C libft/ clean

fclean: clean
		@rm -rf $(EXE)
		@rm -rf $(NAME)
		@make -C libft/ fclean

re: fclean all

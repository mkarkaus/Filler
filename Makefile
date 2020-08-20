# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/19 16:56:01 by mkarkaus          #+#    #+#              #
#    Updated: 2020/08/20 12:55:15 by mkarkaus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re exre

NAME = mkarkaus.filler

SRCS_PATH = ./srcs/
SRCS_FILES = main.c get_data.c
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FILES))

LIB = ./libft/libft.a

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@make --no-print-directory -C libft/
	@gcc -o $(NAME) $(FLAGS) $(SRCS) $(LIB)
	@echo "Executable '$(NAME)' created successfully."

clean:
	@make clean --no-print-directory -C libft/
	@rm -rf *.o
	@echo "Object files removed."

fclean: clean
	@make fclean --no-print-directory -C libft/
	@rm -rf $(NAME)
	@echo "Executable $(NAME) removed."

re: fclean all
	@echo "Files recompiled."

exre:
	@gcc -o $(NAME) $(FLAGS) $(SRCS) $(LIB)
	@rm -rf *.o
	@echo "Executable '$(NAME)' created successfully."

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmadau <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/24 14:02:48 by tmadau            #+#    #+#              #
#    Updated: 2018/09/03 17:22:43 by tmadau           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

KGRN = \x1B[32m

CFILES = check.c \

LIB = ./libft/libft.a

INCLUDES = -I./libft

CC = gcc

CF = -c -Wall -Wextra -Werror

SDLFLAGS = -lSDL2 -I ~/.brew/include -L ~/.brew/lib

OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	@echo "$(KGRN)+-------------------------------------------------------+"
	@echo "$(KGRN)| WOLF3D LOADING ⚪ ⚪⚪ ⚪⚪⚪ ⚪⚪⚪⚪ ⚪⚪⚪⚪⚪⚪⚪ |"
	@echo "$(KGRN)+-------------------------------------------------------+"
	@make -C libft/
	@$(CC) $(CF) -I $(LIB) -c $(CFILES)
	@$(CC) -o $(NAME) $(OFILES) $(SDLFLAGS)
	@echo "$(KGRN)+-------------------------------------------------------+"
	@echo "$(KGRN)| READY ⭐⭐⭐⭐⭐  press ./wolf3d maps/map00 to run    |"
	@echo "$(KGRN)+-------------------------------------------------------+"

clean:
	@make -C libft/ clean
	@rm -f $(OFILES)
	@echo "$(KGRN)[ ✔ ]\t\tOBJECT PATH REMOVED"

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)
	@echo "$(KGRN)[ ✔ ]\t\tEXECUTABLES REMOVED"

re: fclean all

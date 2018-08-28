# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmadau <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/24 14:02:48 by tmadau            #+#    #+#              #
#    Updated: 2018/08/20 08:59:27 by tmadau           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

KGRN = \x1B[32m

CFILES = test.c \

HF = libft.h \

LIB = ./libft/libft.a

INCLUDES = -I./libft

OFILES = $(CFILES:.c=.o)

CC = gcc

CF = -c -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OFILES)
	@echo "$(KGRN)#*******************************************************#"
	@echo "$(KGRN)# WOLF3D LOADING █ ██ ███ ████ █████ ██████ ███████████ #"
	@echo "$(KGRN)#*******************************************************#"
	@make -C libft/
	@$(CC) $(CF) -I $(LIB) -c $(CFILES)
	@$(CC) -o $(NAME) $(OFILES) -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit
	@echo "$(KGRN)#*******************************************************#"
	@echo "$(KGRN)#             WOLF3D READY [ ✔ ][ ✔ ][ ✔ ]              #"
	@echo "$(KGRN)#*******************************************************#"

clean:
	@make -C libft/ clean
	@rm -f $(OFILES)
	@echo "$(KGRN)[ ✔ ]\t\tOBJECT PATH REMOVED"

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)
	@echo "$(KGRN)[ ✔ ]\t\tEXECUTABLES REMOVED"

re: fclean all

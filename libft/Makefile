# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmadau <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/24 14:02:48 by tmadau            #+#    #+#              #
#    Updated: 2018/09/12 11:45:01 by tmadau           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

KGRN = \x1B[32m

HF = libft.h

CFILES = ft_itoa.c ft_putendl_fd.c ft_strequ.c ft_strnequ.c ft_lstdelone.c \
		 ft_memalloc.c ft_putnbr.c ft_striter.c ft_strnew.c ft_lstdel.c \
		 ft_memccpy.c ft_putnbr_fd.c ft_striteri.c ft_strnstr.c ft_lstadd.c \
		 ft_atoi.c ft_memchr.c ft_putstr.c ft_strjoin.c ft_strrchr.c ft_lstiter.c \
		 ft_bzero.c ft_memcmp.c ft_putstr_fd.c ft_strlcat.c ft_strsplit.c \
		 ft_isalnum.c ft_memcpy.c ft_strcat.c ft_strlen.c ft_strstr.c ft_lstmap.c \
		 ft_isalpha.c ft_memdel.c ft_strchr.c ft_strmap.c ft_strsub.c \
		 ft_isascii.c ft_memmove.c ft_strclr.c ft_strmapi.c ft_strtrim.c \
		 ft_isdigit.c ft_memset.c ft_strcmp.c ft_strncat.c ft_tolower.c \
		 ft_islower.c ft_putchar.c ft_strcpy.c ft_strncmp.c ft_toupper.c \
		 ft_isprint.c ft_putchar_fd.c ft_strdel.c ft_strncpy.c ft_lstnew.c \
		 ft_isupper.c ft_putendl.c ft_strdup.c ft_convert.c get_next_line.c \
		 ft_wordcount.c get_matrix.c fill_matrix.c alloc_matrix.c \

OFILES = $(CFILES:.c=.o)

CC = gcc

CF = -c -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@echo "$(KGRN)Creating : $(NAME) [ ✔ ]"
	@$(CC) $(CF) $(CFILES) -I $(HF)
	@ar -rcs $(NAME) $(OFILES)
	@echo "$(KGRN)Compiled : c_files [ ✔ ]"

clean:
	@rm -f $(OFILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all

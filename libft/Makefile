# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: torsini <torsini@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 11:00:22 by torsini           #+#    #+#              #
#    Updated: 2024/03/20 11:10:31 by torsini          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAG = -Wall -Werror -Wextra

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
      ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
      ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
      ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c \
      ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
      ft_strmapi.c ft_striteri.c \
      ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
      
# printf
OBJS_PRINTF = $(SRC_PRINTF:.c=.o)
SRC_PRINTF = ft_printf/ft_printf.c\
	     ft_printf/ft_printf_funcs.c\
	     ft_printf/ft_printf_hex.c\
	     ft_printf/ft_printf_p.c\
	     ft_printf/ft_printf_un.c\

# get_next_line
OBJS_GNL = $(SRC_GNL:.c=.o)
SRC_GNL	= gnl/get_next_line.c\



HEADER = libft.h

OBJ = $(SRC:.c=.o)
NAME = libft.a

$(NAME): $(OBJ) $(OBJS_PRINTF) $(OBJS_GNL) 
	@$(CC) $(FLAG) -c $(SRC)
	@ar rcs $(NAME) $(OBJ) $(OBJS_PRINTF) $(OBJS_GNL)
	@ranlib $(NAME)

all: $(NAME)

clean:
	@rm -rf $(OBJ) $(OBJS_PRINTF) $(OBJS_GNL)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

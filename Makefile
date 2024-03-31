# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: torsini <torsini@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/29 10:15:07 by torsini           #+#    #+#              #
#    Updated: 2024/03/29 10:59:58 by torsini          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
MLX = mlx/libmlx.a
INCLUDES = -I./ -I./libft -I./mlx
LFLAGS = -L./libft -lft -L./mlx -lmlx -lXext -lX11 -lm
SRC = source/test.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $(NAME)

$(LIBFT):
	make -C libft

$(MLX):
	make -C mlx

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make -C libft clean
	make -C mlx clean
	rm -f $(OBJ)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

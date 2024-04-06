/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moov.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torsini <torsini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:38:45 by torsini           #+#    #+#             */
/*   Updated: 2024/04/06 11:06:24 by torsini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_check(t_data *game)
{
	if (game->map[game->p_pos.row][game->p_pos.col] == 'C')
	{
		game->coins--;
		game->score++;
		ft_putstr_fd("Score: ", 1);
		ft_putnbr_fd(game->score, 1);
		ft_putstr_fd("\n", 1);
	}
	if (game->map[game->p_pos.row][game->p_pos.col] == 'E' && game->coins == 0)
	{
		ft_putstr_fd("\nVous êtes tombé dans le Trou Noir !\n", 1);
		ft_putstr_fd("Profitez du reste de votre vie dans le vide !\n", 1);
		on_destroy(game);
	}
	if (game->map[game->p_pos.row][game->p_pos.col] == 'B')
	{
		ft_putendl_fd("\nAttention ! C'est un bug !", 1);
		ft_putendl_fd("Oh non, on dirait que votre code est infecté", 1);
		ft_putendl_fd("----------------------------------------", 1);
		ft_putendl_fd("Vous êtes un perdant, bébé", 1);
		ft_putendl_fd("Un perdant, bon sang, bébé", 1);
		ft_putendl_fd("Vous êtes un petit pleurnichard foutu", 1);
		ft_putendl_fd("Vous êtes un perdant, tout comme moi", 1);
		on_destroy(game);
	}
}

void	move_player(t_data *game, int row, int col)
{
	ft_printf("move_player called with dx=%d, dy=%d\n", row, col);
	if (game->map[row][col] == 'E' && game->coins != 0)
	{
		ft_putstr_fd("You need to collect all the coins first!\n", 1);
		return ;
	}
	game->map[game->p_pos.row][game->p_pos.col] = '0';
	game->p_pos.row = row;
	game->p_pos.col = col;
	move_check(game);
	game->map[game->p_pos.row][game->p_pos.col] = 'P';
	game->moves++;
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(game->moves, 1);
	ft_putstr_fd("\n", 1);
	fill_window(game);
}

void	update_player_position(t_data *game, int keycode)
{
	ft_printf("update_player_position called with keycode %d\n", keycode);

	game->frames++;
	if (keycode == 119)
	{
		game->p_pos.direction = BACK;
		if (game->map[game->p_pos.row - 1][game->p_pos.col] != '1')
			move_player(game, game->p_pos.row - 1, game->p_pos.col);
	}
	else if (keycode == 97)
	{
		game->p_pos.direction = LEFT;
		if (game->map[game->p_pos.row][game->p_pos.col - 1] != '1')
			move_player(game, game->p_pos.row, game->p_pos.col - 1);
	}
	else if (keycode == 115)
	{
		game->p_pos.direction = FRONT;
		if (game->map[game->p_pos.row + 1][game->p_pos.col] != '1')
			move_player(game, game->p_pos.row + 1, game->p_pos.col);
	}
	else if (keycode == 100)
	{
		game->p_pos.direction = RIGHT;
		if (game->map[game->p_pos.row][game->p_pos.col + 1] != '1')
			move_player(game, game->p_pos.row, game->p_pos.col + 1);
	}
}
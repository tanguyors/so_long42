/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printgame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torsini <torsini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:03:50 by torsini           #+#    #+#             */
/*   Updated: 2024/04/05 15:30:55 by torsini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_coin(t_data *game, int i, int index)
{
	mlx_put_image_to_window(game->mlx, game->win, game->textures.ground, i * 32,
		(index * 32));
	mlx_put_image_to_window(game->mlx, game->win, game->textures.coin, i * 32,
		(index * 32));
}

void	print_player(t_data *game, int i, int index)
{
	mlx_put_image_to_window(game->mlx, game->win, game->textures.ground, i * 32,
		(index * 32));
	if (game->p_pos.direction == FRONT)
		mlx_put_image_to_window(game->mlx, game->win, game->textures.player, i
			* 32, (index * 32));
	else if (game->p_pos.direction == BACK)
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures.player_back, i * 32, (index * 32));
	else if (game->p_pos.direction == LEFT)
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures.player_left, i * 32, (index * 32));
	else if (game->p_pos.direction == RIGHT)
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures.player_right, i * 32, (index * 32));
}

void	print_exit(t_data *game, int i, int index)
{
	mlx_put_image_to_window(game->mlx, game->win, game->textures.ground, i * 32,
		(index * 32));
	mlx_put_image_to_window(game->mlx, game->win, game->textures.door, i * 32,
		(index * 32));
}

void	print_wall(t_data *game, int i, int index)
{
	if (game->frames % 8 == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->textures.wall, i
			* 32, (index * 32));
	else if (game->frames % 8 == 4)
		mlx_put_image_to_window(game->mlx, game->win, game->textures.wall2, i
			* 32, (index * 32));
}

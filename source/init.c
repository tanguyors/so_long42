/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torsini <torsini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:45:00 by torsini           #+#    #+#             */
/*   Updated: 2024/04/05 16:03:12 by torsini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_textures(t_data *game)
{
	game->textures.ground = NULL;
	game->textures.coin = NULL;
	game->textures.door = NULL;
	game->textures.wall = NULL;
	game->textures.wall2 = NULL;
	game->textures.player = NULL;
	game->textures.player_left = NULL;
	game->textures.player_right = NULL;
	game->textures.player_back = NULL;
	game->textures.moves = NULL;
}

void	init_struct(t_data *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->width = 0;
	game->height = 0;
	game->x = 0;
	game->y = 0;
	game->map = NULL;
	game->map_dup = NULL;
	game->rows = 0;
	game->cols = 0;
	game->player = 0;
	game->p_pos.row = 0;
	game->p_pos.col = 0;
	game->p_pos.direction = FRONT;
	game->coins = 0;
	game->exit = 0;
	game->moves = 0;
	game->score = 0;
	game->frames = 0;
	init_textures(game);
}

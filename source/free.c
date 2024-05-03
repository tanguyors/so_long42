/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torsini <torsini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:46:20 by torsini           #+#    #+#             */
/*   Updated: 2024/04/05 12:47:38 by torsini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(t_data *game)
{
	int	i;

	i = 0;
	while (i < game->rows)
	{
		free(game->map[i]);
		free(game->map_dup[i]);
		game->map[i] = NULL;
		game->map_dup[i] = NULL;
		i++;
	}
	free(game->map);
	free(game->map_dup);
	game->map = NULL;
	game->map_dup = NULL;
}

void	free_textures(t_data *game)
{
	mlx_destroy_image(game->mlx, game->textures.coin);
	mlx_destroy_image(game->mlx, game->textures.door);
	mlx_destroy_image(game->mlx, game->textures.ground);
	mlx_destroy_image(game->mlx, game->textures.wall);
	mlx_destroy_image(game->mlx, game->textures.wall2);
	mlx_destroy_image(game->mlx, game->textures.player);
	mlx_destroy_image(game->mlx, game->textures.player_left);
	mlx_destroy_image(game->mlx, game->textures.player_right);
	mlx_destroy_image(game->mlx, game->textures.player_back);
	mlx_destroy_image(game->mlx, game->textures.moves);
}

int	suppresion(t_data *game)
{
	free_map(game);
	free_textures(game);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
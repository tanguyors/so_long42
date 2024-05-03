/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torsini <torsini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:34:30 by torsini           #+#    #+#             */
/*   Updated: 2024/04/05 14:01:48 by torsini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	move_possibility(t_data *game, int row, int col)
{
	return (game->map[row][col] != '1');
}

void	floodfill(t_data *game, int row, int col)
{
	if (!move_possibility(game, row, col) || game->map_dup[row][col] == '-'
		|| game->map_dup[row][col] == 'B')
		return ;
	game->map_dup[row][col] = '-';
	floodfill(game, row - 1, col);
	floodfill(game, row + 1, col);
	floodfill(game, row, col - 1);
	floodfill(game, row, col + 1);
}

void	check_flood(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->cols)
		{
			if (game->map_dup[i][j] == 'C' || game->map_dup[i][j] == 'E')
				msg_err("Error\n map invalide");
			j++;
		}
		i++;
	}
}

void	duplicate_map(t_data *game)
{
	int i;

	game->map_dup = (char **)malloc(sizeof(char *) * (game->rows + 1));
	if (game->map_dup == NULL)
		msg_err("Error\n Memory allocation failed.");
	i = 0;
	while (i < game->rows)
	{
		game->map_dup[i] = ft_strdup(game->map[i]);
		if (game->map_dup[i] == NULL)
			msg_err("Error\n Memory allocation failed.");
		i++;
	}
	game->map_dup[i] = NULL;
	floodfill(game, game->p_pos.row, game->p_pos.col);
	check_flood(game);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torsini <torsini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:30:35 by torsini           #+#    #+#             */
/*   Updated: 2024/04/05 13:32:33 by torsini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	checkmap(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->cols)
		{
			if (i == 0 || i == game->rows - 1)
			{
				if (game->map[i][j] != '1')
					msg_err("Error\n map invalide.");
			}
			else if (j == 0 || j == game->cols - 1)
			{
				if (game->map[i][j] != '1')
					msg_err("Error\n map invalide");
			}
			j++;
		}
		i++;
	}
}

void	check_last_row(t_data *game)
{
	int	i;

	i = 0;
	while (i < game->cols)
	{
		if (game->map[game->rows - 1][i] != '1')
			msg_err("Error\n map invalide");
		i++;
	}
	if (game->map[game->rows - 1][i] != '\0' && game->map[game->rows
		- 1][i] != '\n')
		msg_err("Error\n map invalide");
}

void	is_rect(t_data *game)
{
	int	i;
	int	row_len;

	i = 0;
	while (i < game->rows - 1)
	{
		row_len = ft_strlen(game->map[i]) - 1;
		if (row_len != game->cols)
			msg_err("Error\n map invalide");
		i++;
	}
	if (game->cols < 3 || game->rows < 3)
		msg_err("Error\n map invalide");
	if (game->cols == game->rows)
		msg_err("Error\n map invalide");
}

void	count_game_element(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->rows)
	{
		j = -1;
		while (++j < game->cols)
		{
			if (game->map[i][j] == 'P')
			{
				game->p_pos.row = i;
				game->p_pos.col = j;
				game->player++;
			}
			else if (game->map[i][j] == 'E')
				game->exit++;
			else if (game->map[i][j] == 'C')
				game->coins++;
			else if (game->map[i][j] != '1' && game->map[i][j] != '0'
				&& game->map[i][j] != 'B')
				msg_err("Error\n map invalide");
		}
		i++;
	}
}

void	check_map(t_data *game)
{
	checkmap(game);
	check_last_row(game);
	is_rect(game);
	count_game_element(game);
	if (game->exit != 1 || game->coins < 1 || game->player != 1)
		msg_err("Invalid map.");
}
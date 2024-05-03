/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torsini <torsini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:30:00 by torsini           #+#    #+#             */
/*   Updated: 2024/04/05 13:58:25 by torsini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_rows(t_data *game, char *path_map)
{
	int		fd;
	char	*line;
	int		rows;

	rows = 0;
	fd = open(path_map, O_RDONLY);
	if (fd < 0)
		msg_err("No map found.");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		rows++;
	}
	close(fd);
	free(line);
	game->rows = rows;
}

void	fill_map(t_data *game, char *path_map)
{
	int	fd;
	int	i;

	i = 0;
	get_rows(game, path_map);
	if (game->rows == 0)
		msg_err("Invalid map.");
	fd = open(path_map, O_RDONLY);
	if (fd < 0)
		msg_err("No map found.");
	game->map = (char **)malloc(sizeof(char *) * (game->rows + 1));
	if (game->map == NULL)
		msg_err("Memory allocation failed.");
	while (i < game->rows)
	{
		game->map[i] = get_next_line(fd);
		if (!(game->map[i]))
			break ;
		i++;
	}
	game->map[i] = NULL;
	game->cols = ft_strlen(game->map[0]) - 1;
	close(fd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torsini <torsini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:33:51 by torsini           #+#    #+#             */
/*   Updated: 2024/04/06 11:04:48 by torsini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_hook(int keycode, t_data *game)
{
	ft_printf("key_hook called with keycode %d\n", keycode);
	if (keycode == 119 || keycode == 97 || keycode == 115 || keycode == 100)
		update_player_position(game, keycode);
	else if (keycode == ESC)
		suppresion(game);
	return (0);
}

int	loop_hook(t_data *game)
{
	game->frames++;
	draw_win(game);
	usleep(40000);
	return (0);
}
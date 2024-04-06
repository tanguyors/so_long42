/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torsini <torsini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 12:13:12 by torsini           #+#    #+#             */
/*   Updated: 2024/04/05 16:07:16 by torsini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error_message(char *message)
{
	ft_putstr_fd(message, 1);
	exit(EXIT_FAILURE);
}

void	create_window(t_data *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_message("mlx_init failed.");
	game->win = mlx_new_window(game->mlx, game->cols * 32, game->rows * 32,
			"so_long");
	if (!game->win)
		error_message("mlx_new_window failed.");
	open_images(game);
	fill_window(game);
}

int	main(int ac, char **av)
{
	t_data	game;

	if (ac != 2)
		error_message("Wrong number of arguments. Usage: ./so_long <map.ber>");
	if (!ft_strnstr(av[1], ".ber", ft_strlen(av[1])))
		error_message("Invalid file type. Must be: \"<name>.ber\"");
	init_struct(&game);
	fill_map(&game, av[1]);
	check_map(&game);
	duplicate_map(&game);
	create_window(&game);
	mlx_loop_hook(game.mlx, loop_hook, &game);
	mlx_hook(game.win, 2, 1L<<0, key_hook, &game);
	mlx_hook(game.win, 17, 0, on_destroy, &game);
	mlx_loop(game.mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

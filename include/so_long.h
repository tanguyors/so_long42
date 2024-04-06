/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torsini <torsini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 10:31:42 by torsini           #+#    #+#             */
/*   Updated: 2024/04/06 11:01:23 by torsini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

enum					e_keys
{
	W = 119,
	A = 97,
	S = 115,
	D = 100,
	ESC = 53
};

enum					e_directions
{
	FRONT,
	BACK,
	LEFT,
	RIGHT
};

typedef struct s_textures
{
	void				*ground;
	void				*coin;
	void				*door;
	void				*wall;
	void				*wall2;
	void				*player;
	void				*player_left;
	void				*player_right;
	void				*player_back;
	void				*moves;
}						t_textures;

typedef struct s_player
{
	int					row;
	int					col;
	enum e_directions	direction;
}						t_player;

typedef struct s_data
{
	void				*mlx;
	void				*win;
	int					width;
	int					height;
	int					x;
	int					y;
	char				**map;
	char				**map_dup;
	int					rows;
	int					cols;
	int					player;
	t_player			p_pos;
	int					coins;
	int					exit;
	int					moves;
	int					score;
	t_textures			textures;
	int					frames;
}						t_data;

// checkmap
void					check_closed_map(t_data *game);
void					check_last_row(t_data *game);
void					check_rect(t_data *game);
void					count_map(t_data *game);
void					check_map(t_data *game);

// flood_fill
int						validmove(t_data *game, int row, int col);
void					floodfill(t_data *game, int row, int col);
void					check_flood(t_data *game);
void					duplicate_map(t_data *game);

// printgame
void					print_coin(t_data *game, int i, int index);
void					print_player(t_data *game, int i, int index);
void					print_exit(t_data *game, int i, int index);
void					print_wall(t_data *game, int i, int index);

// printmap
void					print_map(char *line, t_data *game, int index);
void					fill_window(t_data *game);

// openassets
void					open_images(t_data *game);

// init
void					init_textures(t_data *game);
void					init_struct(t_data *game);

// free
void					free_maps(t_data *game);
void					free_textures(t_data *game);
int						on_destroy(t_data *game);

// moov
void					move_check(t_data *game);
void					move_player(t_data *game, int row, int col);
void					update_player_position(t_data *game, int keycode);

// mouvement
int						key_hook(int keycode, t_data *game);
int						loop_hook(t_data *game);

// util
void					get_rows(t_data *game, char *path_map);
void					fill_map(t_data *game, char *path_map);

// main
void					create_window(t_data *game);
void					error_message(char *message);
#endif
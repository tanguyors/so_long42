/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torsini <torsini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 10:31:42 by torsini           #+#    #+#             */
/*   Updated: 2024/03/31 14:55:17 by torsini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JEU_H
#define JEU_H

#include <mlx.h>
#include <stdlib.h>
#include "libft/libft.h" // Modification ici

void *mlx_init();
void *mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
int mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);
int mlx_loop(void *mlx_ptr);

#endif

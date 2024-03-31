/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torsini <torsini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 12:13:12 by torsini           #+#    #+#             */
/*   Updated: 2024/03/31 17:33:34 by torsini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

typedef struct  s_img
{
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_img;

typedef struct  s_data
{
    void        *mlx_ptr;
    void        *win;
    t_img       img;
    int         color; 
    int         circle_x; 
    int         circle_y;
    void        *texture;   // Ajouté
    int         texture_width;  // Ajouté
    int         texture_height; // Ajouté
}               t_data;


void draw_circle(t_data *data, int center_x, int center_y, int radius)
{
    for (int y = -radius; y <= radius; y++)
    {
        for (int x = -radius; x <= radius; x++)
        {
            if (x * x + y * y <= radius * radius)
            {
                mlx_pixel_put(data->mlx_ptr, data->win, center_x + x, center_y + y, data->color);
            }
        }
    }
}


int render_next_frame(t_data *data)
{
    mlx_clear_window(data->mlx_ptr, data->win);
    draw_circle(data, data->circle_x, data->circle_y, 11);  // Dessine un cercle avec un rayon de 50
    return (0);
}


void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->img.addr + (y * data->img.line_length + x * (data->img.bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int key_press(int keycode, t_data *data)
{
    ft_printf("key pressed : %d\n", keycode);
    if (keycode == 65307) // 65307 est le code de la touche Echap
    {
        mlx_destroy_window(data->mlx_ptr, data->win);
        exit(0);
    }
    else if (keycode == 'w')  // W
        data->circle_y -= 10;
    else if (keycode == 'a')  // A
        data->circle_x -= 10;
    else if (keycode == 's')  // S
        data->circle_y += 10;
    else if (keycode == 'd')  // D
        data->circle_x += 10;
    return (0);
}

int close_win(t_data *data)
{
    mlx_destroy_window(data->mlx_ptr, data->win);
    exit(0);
    return (0);
}

int mouse_move(int x, int y, t_data *data)
{
    (void)data;  // Ajoutez cette ligne
    ft_printf("Mouse position: (%d, %d)\n", x, y);
    return (0);
}

int mouse_press(int button, int x, int y, t_data *data)
{
    (void)data;  // Ajoutez cette ligne
    ft_printf("Mouse pressed at: (%d, %d) with button: %d\n", x, y, button);
    return (0);
}

int mouse_enter_leave(int x, int y, t_data *data)
{
    (void)data; // Ajoutez cette ligne

    if (x >= 0 && x <= 800 && y >= 0 && y <= 600)
        ft_printf("Hello!\n");
    else
        ft_printf("Bye!\n");
    return (0);
}

int main()
{
    t_data data;

    // Initialisation de MiniLibX
    data.mlx_ptr = mlx_init();
    data.win = mlx_new_window(data.mlx_ptr, 800, 600, "FENETRE");
    data.color = 0xFFFFFF;
    data.circle_x = 400;
    data.circle_y = 300;

    // Création d'une nouvelle image
    data.img.img = mlx_new_image(data.mlx_ptr, 1920, 1080);
    data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel, &data.img.line_length,
            &data.img.endian);

    // Utilisation de my_mlx_pixel_put pour dessiner un pixel
    my_mlx_pixel_put(&data, 5, 5, 0x00FF0000);

    // Affichage de l'image dans la fenêtre
    mlx_put_image_to_window(data.mlx_ptr, data.win, data.img.img, 0, 0);

    // Gestion des crochets pour les événements
    mlx_hook(data.win, 2, 1L<<0, &key_press, &data); // Gestion des événements de clavier
    mlx_hook(data.win, 17, 1L<<0, &close_win, &data); // Gestion de la fermeture de la fenêtre
    mlx_hook(data.win, 6, 1L<<0, &mouse_enter_leave, &data); // Gestion de l'entrée et de la sortie de la souris
    mlx_key_hook(data.win, key_press, &data);
    mlx_mouse_hook(data.win, mouse_press, &data);
    mlx_loop_hook(data.mlx_ptr, mouse_move, &data);
    mlx_loop_hook(data.mlx_ptr, render_next_frame, &data);

    // Boucle principale pour maintenir la fenêtre ouverte
    mlx_loop(data.mlx_ptr);

    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:05:25 by jbarette          #+#    #+#             */
/*   Updated: 2022/10/28 16:20:59 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	create_image(t_params *params)
{
	int		x;
	int		y;
	
	x = 0;
	y = 0;
	while (x < params->nbr_lines)
	{
		while (y < ft_strlen(params->map[x]))
		{
			if (params->map[x][y] == '1')
				my_mlx_pixel_put(&params->img, y * 10, x * 10, 0x00FF0000);
			else if (params->map[x][y] == '0')
				my_mlx_pixel_put(&params->img, y * 10, x * 10, 0x00FFFAFA);
			else
				my_mlx_pixel_put(&params->img, params->pos_y * 10, params->pos_x * 10, 0x00FFF000);
			y++;
		}
		y = 0;
		x++;
	}
	mlx_put_image_to_window(params->mlx, params->mlx_win, params->img.img, 0, 0);
	return (0);
}

int	event_press(int keycode, t_params *params)
{
	if (keycode == 13)
		params->pos_x += 1;
	return (0);
}

int	start_game(t_params *params)
{
	/*
	*	Créer une image
	*	Récupérer son adresse
	*	Ecrire les pixels dedans, un pixel dans la map = 10 x 10 pixels réel
	*	Envoyer l'image dans la window une fois finie
	*	Utiliser mlx_hook pour récupérer les touches clavier + mlx_loop_hook qui exécutera la fonction qui créait l'image à chaque évènement
	*/
	params->mlx = mlx_init();
	params->mlx_win = mlx_new_window(params->mlx, 640, 480, "Hello World!");
	params->img.img = mlx_new_image(params->mlx, 640, 480);
	params->img.addr = mlx_get_data_addr(params->img.img, &params->img.bits_per_pixel, &params->img.line_length, &params->img.endian);
	mlx_loop_hook(params->mlx, &create_image, params);
	mlx_hook(params->mlx_win, 2, 0, &event_press, params);
	mlx_hook(params->mlx_win, 17, 0, &close_win, NULL);
	mlx_loop(params->mlx);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:36:17 by jbarette          #+#    #+#             */
/*   Updated: 2022/11/16 15:03:49 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	event_press(int keycode, t_params *params)
{
	if (keycode == 13)
	{
		if (params->map[params->pos_x + (int)params->dirX * (int)params->moveSpeed][params->pos_y] == '0')
		{
			params->pos_x += params->dirX * params->moveSpeed;
		}
		if (params->map[params->pos_x + (int)params->dirY * (int)params->moveSpeed] == NULL)
			params->pos_y += params->dirY * params->moveSpeed;
	}
	// if (keycode == 1)
	// {
	// 	params->pos_y += 1;
	// 	if (params->map[params->pos_y][params->pos_x] == '1')
	// 		params->pos_y -= 1;
	// }
	// if (keycode == 0)
	// {
	// 	params->pos_x -= 1;
	// 	if (params->map[params->pos_y][params->pos_x] == '1')
	// 		params->pos_x += 1;
	// }
	// if (keycode == 2)
	// {
	// 	params->pos_x += 1;
	// 	if (params->map[params->pos_y][params->pos_x] == '1')
	// 		params->pos_x -= 1;
	// }
	if (keycode == 53)
		close_win(params);
	mlx_destroy_image(params->mlx, params->img.img);
	return (0);
}
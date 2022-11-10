/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:05:25 by jbarette          #+#    #+#             */
/*   Updated: 2022/11/10 17:12:32 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_image(t_params *params)
{
	params->img.img = mlx_new_image(params->mlx, WidthScreen, HeightScreen);
	params->img.addr = mlx_get_data_addr(params->img.img, &params->img.bits_per_pixel, &params->img.line_length, &params->img.endian);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void verLine(int x, int drawStart, int drawEnd, t_params *params)
{
	while (drawStart < drawEnd)
	{
		my_mlx_pixel_put(&params->img, x, drawStart, 0x00FFFF);
		drawStart++;
	}
}

int	draw(t_params *params)
{
	double posX = params->pos_x, posY = params->pos_y;  //x and y start position
	double dirX = -1, dirY = 0; //initial direction vector
	double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

	clock_t start = 0;
	clock_t end;
	double time = 0; //time of current frame
	double oldTime = 0; //time of previous frame

	int	x = 0;

	while (x < WidthScreen)
	{
		double cameraX = 2 * x / (double)WidthScreen - 1; //x-coordinate in camera space
		double rayPosX = posX;
		double rayPosY = posY;
		double rayDirX = dirX + planeX * cameraX;
		double rayDirY = dirY + planeY * cameraX;
		int mapX = (int)rayPosX;
		int mapY = (int)rayPosY;
		double sideDistX;
		double sideDistY;
		double deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
		double deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
		double perpWallDist;
		int stepX;
		int stepY;
		int hit = 0; //was there a wall hit?
		int side = 0; //was a NS or a EW wall hit?

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (rayPosX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - rayPosX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (rayPosY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - rayPosY) * deltaDistY;
		}

		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (params->map[mapX][mapY] == '1')
				hit = 1;
		}

		if (side == 0)
			perpWallDist = (mapX - rayPosX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - rayPosY + (1 - stepY) / 2) / rayDirY;
		int lineHeight = (int)(HeightScreen / perpWallDist);
		int drawStart = -lineHeight / 2 + HeightScreen / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + HeightScreen / 2;
		if (drawEnd >= HeightScreen)
			drawEnd = HeightScreen - 1;
		verLine(x, drawStart, drawEnd, params);
		x++;
	}
	end = start;
	start = clock();
	double frameTime = (start - end) / CLOCKS_PER_SEC; 
	double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
	double rotSpeed = frameTime * 3.0;
	mlx_put_image_to_window(params->mlx, params->mlx_win, params->img.img, 0, 0);
	return (0);
}

void	write_to_image(t_params *params)
{
	create_image(params);
	mlx_loop_hook(params->mlx, &draw, params);
	mlx_hook(params->mlx_win, 2, 0, &event_press, params);
	mlx_hook(params->mlx_win, 17, 0, &close_win, NULL);
	mlx_loop(params->mlx);
}

int	start_game(t_params *params)
{
	params->mlx = mlx_init();
	params->mlx_win = mlx_new_window(params->mlx, WidthScreen, HeightScreen, "Hello World!");
	write_to_image(params);
	return (0);
}
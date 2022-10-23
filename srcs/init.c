/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeremybarette <jeremybarette@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:29:34 by jbarette          #+#    #+#             */
/*   Updated: 2022/10/23 14:02:16 by jeremybaret      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texture	*init_texture(void)
{
	t_texture	*texture;

	texture = malloc(sizeof(t_texture));
	texture->east = NULL;
	texture->north = NULL;
	texture->south = NULL;
	texture->west = NULL;
	return (texture);
}

t_color	*init_color(void)
{
	t_color	*color;

	color = malloc(sizeof(t_color));
	color->ceil = NULL;
	color->floor = NULL;
	return (color);
}

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map->map = NULL;
	map->pos = 0;
	map->nbr_lines = 0;
	return (map);
}

void	free_structure(t_texture *texture, t_color *color)
{
	free(texture->east);
	free(texture->north);
	free(texture->south);
	free(texture->west);
	free(color->ceil);
	free(color->floor);
	// free_array(map->map);
	free(texture);
	free(color);
	// free(map);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}
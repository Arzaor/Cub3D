/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeremybarette <jeremybarette@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:12:49 by jbarette          #+#    #+#             */
/*   Updated: 2022/10/23 05:53:35 by jeremybaret      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_texture	*texture;
	t_color		*color;
	t_map		*map;

	if (argc != 2)
		ft_exit("Deux arguments sont nécessaires.");
	texture = init_texture();
	color = init_color();
	map = init_map();
	parsing(texture, color, map, argv[1]);
	// printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n", texture->north, texture->south, texture->west, texture->east, color->ceil, color->floor, map->map[0]);
	// On lance le jeu ici
	free_structure(texture, color, map);
	// while (1) ;
	return (0);
}
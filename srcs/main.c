/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:12:49 by jbarette          #+#    #+#             */
/*   Updated: 2022/10/18 15:28:00 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_texture	*texture;
	t_color		*color;

	if (argc != 2)
		ft_exit("Deux arguments sont nécessaires.");
	texture = init_texture();
	color = init_color();
	parsing(texture, color, argv[1]);
	printf("%s\n%s\n%s\n%s\n%s\n%s\n", texture->north, texture->south, texture->west, texture->east, color->ceil, color->floor);
	// On lance le jeu ici
	free_structure(texture, color);
	// while (1) ;
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:12:49 by jbarette          #+#    #+#             */
/*   Updated: 2022/10/17 16:43:33 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_texture	*texture;
	t_color		*color;

	if (argc != 2)
	{
		printf("Error\nDeux arguments sont nécessaires.\n");
		exit (0);
	}
	texture = init_texture();
	color = init_color();
	parsing(texture, color, argv[1]);
	printf("%s\n%s\n%s\n%s\n%s\n%s\n", texture->north, texture->south, texture->west, texture->east, color->ceil, color->floor);
	// On lance le jeu ici
	return (0);
}
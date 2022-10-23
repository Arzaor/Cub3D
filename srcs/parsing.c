/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeremybarette <jeremybarette@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:31:44 by jbarette          #+#    #+#             */
/*   Updated: 2022/10/23 05:52:15 by jeremybaret      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parsing(t_texture *texture, t_color *color, t_map *map, char *file)
{
	int index;

	index = 0;
	check_extension(file);
	index = read_file(texture, color, map, file);
	isempty_options(texture, color);
	parser_map(map, index);
}

void	check_extension(char *file)
{
	int	size;

	size = ft_strlen(file);
	if (!(file[size - 1] == 'b' && file[size - 2] == 'u' && file[size - 3] == 'c' && file[size - 4] == '.'))
		ft_exit("L'extension du fichier est incorrect.");
}

void	isempty_options(t_texture *texture, t_color *color)
{
	if (texture->east == NULL \
		|| texture->north == NULL \
		|| texture->south == NULL \
		|| texture->west == NULL)
		ft_exit("Des textures sont manquantes dans la map.");
	if (color->ceil == NULL || color->floor == NULL)
		ft_exit("Des couleurs sont manquantes dans la map.");
}

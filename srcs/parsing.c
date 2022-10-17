/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:31:44 by jbarette          #+#    #+#             */
/*   Updated: 2022/10/17 16:32:43 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parsing(t_texture *texture, t_color *color, char *file)
{
	check_extension(file);
	read_file(texture, color, file);
	check_options_map(texture, color);
}

void	check_extension(char *file)
{
	int	size;

	size = ft_strlen(file);
	if (!(file[size - 1] == 'b' && file[size - 2] == 'u' && file[size - 3] == 'c' && file[size - 4] == '.'))
	{
		printf("Error\nL'extension du fichier est incorrect.\n");
		exit (0);
	}
}

void	check_options_map(t_texture *texture, t_color *color)
{
	if (texture->east == NULL \
		|| texture->north == NULL \
		|| texture->south == NULL \
		|| texture->west == NULL)
	{
		printf("Error\nDes textures sont manquantes dans la map.\n");
		exit (0);
	}
	if (color->ceil == NULL || color->floor == NULL)
	{
		printf("Error\nDes couleurs sont manquantes dans la map.\n");
		exit (0);
	}
}

void	read_file(t_texture *texture, t_color *color, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY, 0777);
	if (!(fd))
		printf("Error\nEchec de la lecture du fichier.");
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[0] == 'N' && line[1] == 'O')
			save_texture(texture, line, 1);
		else if (line[0] == 'S' && line[1] == 'O')
			save_texture(texture, line, 2);
		else if (line[0] == 'W' && line[1] == 'E')
			save_texture(texture, line, 3);
		else if (line[0] == 'E' && line[1] == 'A')
			save_texture(texture, line, 4);
		if (line[0] == 'F')
			save_color(color, line, 1);
		else if (line[0] == 'C')
			save_color(color, line, 2);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
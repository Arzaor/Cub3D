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

void	parsing(char *file)
{
	check_extension(file);
	read_file(file);
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

void	read_file(char *file)
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
			save_texture(line, 1);
		else if (line[0] == 'S' && line[1] == 'O')
			save_texture(line, 2);
		else if (line[0] == 'W' && line[1] == 'E')
			save_texture(line, 3);
		else if (line[0] == 'E' && line[1] == 'A')
			save_texture(line, 4);
		// if (line[0] == 'F')
		// 	save_color(line, 1);
		// else if (line[0] == 'C')
		// 	save_color(line, 2);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeremybarette <jeremybarette@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 02:59:56 by jeremybaret       #+#    #+#             */
/*   Updated: 2022/10/23 05:51:20 by jeremybaret      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		count_lines(char *file)
{
	int		fd;
	char	*line;
	int		count;
	
	fd = open(file, O_RDONLY, 0777);
	if (!(fd))
		ft_exit("Echec de la lecture du fichier.");
	line = get_next_line(fd);
	count = 0;
	while (line != NULL)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return(count);
}

int	read_file(t_texture *texture, t_color *color, t_map *map, char *file)
{
	int		fd;
	char	*line;
	int		k;

	fd = open(file, O_RDONLY, 0777);
	k = 0;
	map->map = malloc(sizeof(char *) * count_lines(file));
	line = get_next_line(fd);
	if (!(fd))
		ft_exit("Echec de la lecture du fichier.");
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
		else if (line[0] == 'F')
			save_color(color, line, 1);
		else if (line[0] == 'C')
			save_color(color, line, 2);
		else
		{
			if (ft_strlen(line) > 1)
				map->map[k++] = ft_strdup(ft_strtrim(line, "\n"));
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (k);
}

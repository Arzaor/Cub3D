/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:32:26 by jbarette          #+#    #+#             */
/*   Updated: 2022/10/18 14:58:22 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*cpy_texture(char	*line)
{
	char		*texture_trim;
	char		*texture_w_id;
	int			i;
	int			k;

	i = 2;
	k = 0;
	while (line[i] != '.')
		i++;
	texture_trim = ft_strtrim(line, "\n");
	texture_w_id = malloc(sizeof(char) * ft_strlen(texture_trim));
	while (texture_trim[i])
		texture_w_id[k++] = texture_trim[i++];
	texture_w_id[k] = '\0';
	free(texture_trim);
	return (texture_w_id);
}

void	save_texture(t_texture *texture, char *line, int id)
{
	char		*texture_w_id;
	
	texture_w_id = cpy_texture(line);
	if (open(texture_w_id, O_RDONLY) == -1)
		ft_exit("Une ou des textures sont introuvables.");
	if (id == 1 && texture->north == NULL)
		texture->north = ft_strdup(texture_w_id);
	else if (id == 2 && texture->south == NULL)
		texture->south = ft_strdup(texture_w_id);
	else if (id == 3 && texture->west == NULL)
		texture->west = ft_strdup(texture_w_id);
	else if (id == 4 && texture->east == NULL)
		texture->east = ft_strdup(texture_w_id);
	else
		ft_exit("Interdit de dupliquer les paramètres.");
	free(texture_w_id);
}
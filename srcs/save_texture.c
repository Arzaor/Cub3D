/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:32:26 by jbarette          #+#    #+#             */
/*   Updated: 2022/10/17 16:43:49 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*delete_id(char *line)
{
	char	*texture_w_id;
	int i;
	int	k;

	i = 3;
	k = 0;
	texture_w_id = malloc(sizeof(char) * ft_strlen(line));
	while (line[i])
	{
		texture_w_id[k] = line[i];
		k++;
		i++;
	}
	return (texture_w_id);
}

void	save_texture(char *line, int id)
{
	char		*texture_w_id;
	t_texture	*textures;

	texture_w_id = NULL;
	if (id == 1)
	{
		texture_w_id = delete_id(line);
		textures->north = ft_strdup(texture_w_id);
	}
	else if (id == 2)
	{
		texture_w_id = delete_id(line);
		textures->south = ft_strdup(texture_w_id);
	}
	else if (id == 3)
	{
		texture_w_id = delete_id(line);
		textures->west = ft_strdup(texture_w_id);
	}
	else if (id == 4)
	{
		texture_w_id = delete_id(line);
		textures->east = ft_strdup(texture_w_id);
	}
	free(texture_w_id);
}
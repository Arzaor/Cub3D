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

void	save_texture(t_texture *texture, char *line, int id)
{
	char		**texture_w_id;
	int			i;

	i = 2;
	while (line[i] != '.')
		i++;
	texture_w_id = ft_split(line, line[i - 1]);
	if (id == 1)
		texture->north = ft_strdup(texture_w_id[1]);
	else if (id == 2)
		texture->south = ft_strdup(texture_w_id[1]);
	else if (id == 3)
		texture->west = ft_strdup(texture_w_id[1]);
	else if (id == 4)
		texture->east = ft_strdup(texture_w_id[1]);
	free_array(texture_w_id);
}
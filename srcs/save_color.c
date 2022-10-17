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

void	save_color(t_color *color, char *line, int id)
{
	char		**color_w_id;
	int			i;

	i = 1;
	while (!ft_isdigit(line[i]))
		i++;
	color_w_id = ft_split(line, line[i - 1]);
	if (id == 1)
		color->ceil = ft_strdup(color_w_id[1]);
	else if (id == 2)
		color->floor = ft_strdup(color_w_id[1]);
	free(color_w_id);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:32:26 by jbarette          #+#    #+#             */
/*   Updated: 2022/10/18 15:30:20 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	save_color(t_color *color, char *line, int id)
{
	char	*tab_color;
	int		i;
	int		k;

	tab_color = malloc(sizeof(char) * ft_strlen(line));
	i = 1;
	k = 0;
	while (line[i] != '\n')
	{
		while ((line[i] == '\t') || (line[i] == '\v') || (line[i] == '\f') || (line[i] == '\r')
			|| (line[i] == '\n') || (line[i] == ' '))
			i++;
		if (ft_format_color(line[i]))
			tab_color[k++] = line[i];
		else
			ft_exit("Uniquement des chiffres dans les couleurs.");
		i++;
	}
	tab_color[k] = '\0';
	if (id == 1)
		color->floor = ft_strdup(tab_color);
	else if (id == 2)
		color->ceil = ft_strdup(tab_color);
	free(tab_color);
}
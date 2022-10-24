/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:29:34 by jbarette          #+#    #+#             */
/*   Updated: 2022/10/24 14:04:20 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_params	*init_params(void)
{
	t_params	*params;

	params = malloc(sizeof(t_params));
	params->east = NULL;
	params->north = NULL;
	params->south = NULL;
	params->west = NULL;
	params->ceil = NULL;
	params->floor = NULL;
	params->map = NULL;
	params->pos = 0;
	params->nbr_lines = 0;
	return (params);
}

void	free_structure(t_params *params)
{
	free(params->east);
	free(params->north);
	free(params->south);
	free(params->west);
	free(params->ceil);
	free(params->floor);
	free(params);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}
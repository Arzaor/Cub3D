/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:31:44 by jbarette          #+#    #+#             */
/*   Updated: 2022/10/17 15:49:09 by jbarette         ###   ########.fr       */
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
	int	fd;

	fd = open(file, O_RDONLY, 0777);
	if (!(fd))
		printf("Error\nEchec de la lecture du fichier.");
}
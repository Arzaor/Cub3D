/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:12:49 by jbarette          #+#    #+#             */
/*   Updated: 2022/10/14 10:36:15 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Error\nDeux arguments sont nécessaires.\n");
		exit (0);
	}
	parsing(argv[1]);
	// On lance le jeu ici
	return (0);
}
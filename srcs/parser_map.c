/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 05:29:11 by jeremybaret       #+#    #+#             */
/*   Updated: 2022/10/25 14:55:39 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    save_position(t_params *params)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (x < params->nbr_lines)
    {
        while (y < ft_strlen(params->map[x]))
        {
            if (params->map[x][y] == 'S' || params->map[x][y] == 'N' || params->map[x][y] == 'W' || params->map[x][y] == 'E')
            {
                if (!params->pos)
                    params->pos = params->map[x][y];
                else
                    ft_exit("Une seule position doit être indiqué pour le joueur.");
            }
            y++;
        }
        y = 0;
        x++;
    }
    if (!params->pos)
        ft_exit("Une position est requise pour le joueur.");
}

void    find_space(t_params *params)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (x < params->nbr_lines)
    {
        while (y < ft_strlen(params->map[x]))
        {
            if (params->map[x][y] == ' ')
                params->map[x][y] = '1';
            y++;
        }
        y = 0;
        x++;
    }
}

void    find_wall_first_line(t_params *params)
{
    int y;

    y = 0;
    while (y < ft_strlen(params->map[0]))
    {
        if (params->map[0][y] != '1')
            ft_exit("Uniquement des murs pour la 1ère ligne de la MAP.");
        y++;
    }
    y = 0;
    while (y < ft_strlen(params->map[params->nbr_lines - 1]))
    {
        if (params->map[params->nbr_lines - 1][y] != '1')
            ft_exit("Uniquement des murs pour la dernière ligne de la MAP.");
        y++;
    }
}

void    find_wall(t_params *params)
{
    int x;

    x = 0;
    while (x < params->nbr_lines)
    {
        if (params->map[x][0] != '1' || params->map[x][ft_strlen(params->map[x]) - 1] != '1')
            ft_exit("La carte doit être entourée de mur.");
        x++;
    }
}

void    parser_map(t_params *params)
{
    save_position(params);
    find_space(params);
    find_wall_first_line(params);
    find_wall(params);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeremybarette <jeremybarette@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 05:29:11 by jeremybaret       #+#    #+#             */
/*   Updated: 2022/10/23 06:12:03 by jeremybaret      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    save_position(t_map *map, int index)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (x < index)
    {
        while (y < ft_strlen(map->map[x]))
        {
            if (map->map[x][y] == 'S' || map->map[x][y] == 'N' || map->map[x][y] == 'W' || map->map[x][y] == 'S' || map->map[x][y] == 'E')
            {
                if (!map->pos)
                    map->pos = map->map[x][y];
                else
                    ft_exit("Une seule position doit être indiqué pour le joueur.");
            }
            y++;
        }
        y = 0;
        x++;
    }
    if (!map->pos)
        ft_exit("Une position est requise pour le joueur.");
}

void    find_space(t_map *map, int index)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (x < index)
    {
        while (y < ft_strlen(map->map[x]))
        {
            if (map->map[x][y] == ' ')
                map->map[x][y] = '1';
            y++;
        }
        y = 0;
        x++;
    }
}

void    find_wall_first_line(t_map *map, int index)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (y < ft_strlen(map->map[0]))
    {
        if (map->map[0][y] != '1')
            ft_exit("Uniquement des murs pour la 1ère ligne de la MAP.");
        y++;
    }
    y = 0;
    while (y < ft_strlen(map->map[index - 1]))
    {
        if (map->map[index - 1][y] != '1')
            ft_exit("Uniquement des murs pour la dernière ligne de la MAP.");
        y++;
    }
}

void    find_wall(t_map *map, int index)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (x < index)
    {
        if (map->map[x][0] != '1' || map->map[x][ft_strlen(map->map[x]) - 1] != '1')
            ft_exit("La carte doit être entourée de mur.");
        x++;
    }
}

void    parser_map(t_map *map, int index)
{
    save_position(map, index);
    find_space(map, index);
    find_wall_first_line(map, index);
    find_wall(map, index);
}
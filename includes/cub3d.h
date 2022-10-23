/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeremybarette <jeremybarette@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:23:12 by jbarette          #+#    #+#             */
/*   Updated: 2022/10/23 14:03:41 by jeremybaret      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>
#include <sys/stat.h>
#include <mlx.h>
#include <fcntl.h>

typedef struct s_texture
{
	char		*north;
	char		*south;
	char		*west;
	char		*east;
}				t_texture;

typedef struct s_color
{
	char		*floor;
	char		*ceil;
}				t_color;

typedef struct t_map
{
	char		**map;
	char		pos;
	int			nbr_lines;
}				t_map;

// PARSING
void	parsing(t_texture *texture, t_color *color, t_map *map, char *file);
void	check_extension(char *file);
void	read_file(t_texture *texture, t_color *color, t_map *map, char *file);
void	isempty_options(t_texture *texture, t_color *color);

// READ_FILE
void    read_line_map(t_map *map, char *line);

// SAVE_TEXTURE
void	save_texture(t_texture *texture, char *line, int id);

// SAVE_COLOR
void	save_color(t_color *color, char *line, int id);
void	check_format_color(char	*color);
char	*create_tab_color(char *line);

// PARSER_MAP
void    parser_map(t_map *map);
void    save_position(t_map *map);

// EXIT
void	ft_exit(char *str);

// INIT
t_texture	*init_texture(void);
t_color		*init_color(void);
t_map		*init_map(void);
void		free_structure(t_texture *texture, t_color *color);
void		free_array(char **array);

// UTILS
int	ft_format_color(int c);
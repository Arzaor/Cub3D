/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:23:12 by jbarette          #+#    #+#             */
/*   Updated: 2022/10/18 15:18:41 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>
#include <mlx.h>
#include <sys/stat.h>
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

// PARSING
void	parsing(t_texture *texture, t_color *color, char *file);
void	check_extension(char *file);
void	read_file(t_texture *texture, t_color *color, char *file);
void	check_options_map(t_texture *texture, t_color *color);

// SAVE_TEXTURE
void	save_texture(t_texture *texture, char *line, int id);

// SAVE_COLOR
void	save_color(t_color *color, char *line, int id);
void	check_format_color(char	*color);
char	*create_tab_color(char *line);

// EXIT
void	ft_exit(char *str);

// INIT
t_texture	*init_texture(void);
t_color		*init_color(void);
void		free_structure(t_texture *texture, t_color *color);
void		free_array(char **array);

// UTILS
int	ft_format_color(int c);
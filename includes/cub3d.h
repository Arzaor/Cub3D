/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:23:12 by jbarette          #+#    #+#             */
/*   Updated: 2022/10/28 16:09:04 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>
#include <sys/stat.h>
#include <mlx.h>
#include <fcntl.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef	struct s_params
{
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		*floor;
	char		*ceil;
	char		**map;
	char		pos;
	int			pos_x;
	int			pos_y;
	int			nbr_lines;
	void		*mlx;
	void		*mlx_win;
	t_data		img;
}				t_params;

// PARSING
void	parsing(t_params *params, char *file);
void	check_extension(char *file);
void	read_file(t_params *params, char *file);
void	isempty_options(t_params *params);

// READ_FILE
void    read_line_map(t_params *params, char *line);

// SAVE_TEXTURE
void	save_texture(t_params *params, char *line, int id);

// SAVE_COLOR
void	save_color(t_params *params, char *line, int id);
void	check_format_color(char	*color);
char	*create_tab_color(char *line);

// PARSER_MAP
void    parser_map(t_params *params);
void    save_position(t_params *params);

// START_GAME
int	start_game(t_params *params);

// EXIT
void	ft_exit(char *str);

// INIT
t_params	*init_params(void);
void		free_structure(t_params *params);
void		free_array(char **array);

// CLOSE
int	close_win();

// UTILS
int	ft_format_color(int c);
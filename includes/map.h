/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeatilga <zeatilga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 18:32:06 by facetint          #+#    #+#             */
/*   Updated: 2024/08/11 15:58:02 by zeatilga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H 
# define MAP_H

# include "vector.h"
# include "map.h"
# include "config.h"

typedef enum e_map_element
{
	EMPTY = 0,
	WALL = 1,
	UNDEFINED = 4
}	t_map_element;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}	t_image;

typedef struct s_texture_data
{
	t_image	north;
	t_image	south;
	t_image	east;
	t_image	west;
	int		floor_color;
	int		ceiling_color;
}	t_texture_data;

typedef struct s_map
{
	t_map_element	**map;
	int				width;
	int				height;
	t_vector		spawn_point;
	t_direction		spawn_direction;
	t_texture_data	texture;
}	t_map;

void			get_metadata(int fd, void *arg);
void			get_metadata_value(char *value);
void			get_map_size(int fd, void *arg);
void			get_map_data(int fd, void *arg);
void			validate_extension(char *str);
void			read_file(char *filename, void *arg,
					int file_line, void func(int, void *));
int				str2rgb(char *str);
int				is_a_map_line(char *line);

void			safe_exit(void);
void			handle_abort(void);
void			error_exit(const char *msg);

#endif

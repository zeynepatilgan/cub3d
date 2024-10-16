/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeatilga <zeatilga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:13:22 by facetint          #+#    #+#             */
/*   Updated: 2024/08/11 21:12:58 by zeatilga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 1080
# define MOVEMENT_SPEED 0.1
# define ROTATION_SPEED 0.05
# define COLLISION_TOLERANCE 0.0005

# include "defines.h"
# include "vector.h"
# include "map.h"

enum	e_keys
{
	ESC = 53,
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	LEFT_ARROW = 123,
	RIGHT_ARROW = 124,
};

typedef struct s_map_metadata
{
	char		*north_texture_file_name;
	char		*south_texture_file_name;
	char		*west_texture_file_name;
	char		*east_texture_file_name;
	int			floor_color;
	int			ceiling_color;
	int			map_content_first_line;
}	t_map_metadata;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_camera
{
	t_vector	dir;
	t_vector	plane;
}	t_camera;

typedef struct s_pressed_keys	t_pressed_keys;

typedef struct s_player
{
	t_vector		position;
	t_camera		camera;
	t_map			map;
	t_mlx			mlx;
	t_pressed_keys	*keys;
	t_image			frame;
}	t_player;

typedef struct s_pressed_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left_arrow;
	int	right_arrow;
}	t_pressed_keys;

int				key_press(int keycode, t_player *player);
int				key_release(int keycode, t_player *player);
void			rotate_player(t_player *player, double clock_dir);
double			move_x(t_player *player, double delta);
double			move_y(t_player *player, double delta);

int				get_pixel(t_image *img, int x, int y);
int				is_surrounded_by_defined(t_map *map, int x, int y);
int				is_map_width_height_zero(t_map map);
int				game_loop(t_player *player);

void			set_pixel(t_image *img, int x, int y, int color);
void			free_all(t_player *player);
void			set_metadata(t_map_metadata *metadata, char *key, char *val);
void			ensure_metadata_unset(t_map_metadata meta);
void			verify_enclosed_with_walls(t_map *map);
void			set_position_and_fill_map(
					t_map *map, char *line, unsigned int x, unsigned int y);
void			read_metadata_from_line(t_map_metadata *metadata, char *line);

t_player		*get_player(void);
t_image			create_img(t_mlx mlx, int height, int width);
t_image			load_xpm(void *mlx, char *path);
t_texture_data	get_textures(void *mlx, t_map_metadata metadata);
t_map			create_map(t_mlx *mlx, char *filename);
t_map_element	char_to_element(char c);
int				is_in_bounds(t_map map, t_coord coord);
t_map_element	get_map_element(t_map map, t_coord coord);
#endif

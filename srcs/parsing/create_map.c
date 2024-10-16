/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeatilga <zeatilga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:14:53 by facetint          #+#    #+#             */
/*   Updated: 2024/08/11 16:00:31 by zeatilga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/config.h"
#include "../../includes/defines.h"
#include "../../minilibx/mlx.h"
#include "../../get_next_line/get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

int	is_spawn_point_not_set(t_map map)
{
	return (map.spawn_point.x == -1 || map.spawn_point.y == -1);
}

t_map	create_map(t_mlx *mlx, char *filename)
{
	t_map			map;
	t_map_metadata	meta;	

	meta = (t_map_metadata){0};
	meta.floor_color = -1;
	meta.ceiling_color = -1;
	map.spawn_point = (t_vector){-1, -1};
	validate_extension(filename);
	read_file(filename, &meta, 0, get_metadata);
	if (meta.map_content_first_line <= 0)
		error_exit(EMPTY_MAP);
	ensure_metadata_unset(meta);
	read_file(filename, &map,
		meta.map_content_first_line, get_map_size);
	if (is_map_width_height_zero(map))
		error_exit(EMPTY_MAP);
	read_file(filename, &map, meta.map_content_first_line, get_map_data);
	verify_enclosed_with_walls(&map);
	if (is_spawn_point_not_set(map))
		error_exit(NO_SPAWN_POINT);
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		error_exit("mlx init error\n");
	map.texture = get_textures(mlx->mlx, meta);
	return (map);
}

void	read_file(char *filename, void *arg,
			int first_line, void func(int, void *))
{
	int	fd;
	int	i;

	i = 1;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit(OPEN_ERROR);
	while (i < first_line)
	{
		get_next_line(fd);
		i++;
	}
	func(fd, arg);
	get_next_line(-1);
	close(fd);
}

void	validate_extension(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len < 4)
		error_exit(MAP_EXTENSION_SHORT);
	if (str[len - 1] != 'b'
		|| str[len - 2] != 'u'
		|| str[len - 3] != 'c'
		|| str[len - 4] != '.')
		error_exit(MAP_EXTENSION_IS_NOT_CUB);
}

void	error_exit(const char *msg)
{
	write(2, VIOLET_BOLD, ft_strlen(VIOLET_BOLD));
	write(2, msg, ft_strlen(msg));
	write(2, ERROR, 6);
	write(2, RESET, ft_strlen(RESET));
	safe_exit();
}

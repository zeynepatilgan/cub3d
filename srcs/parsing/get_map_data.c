/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeatilga <zeatilga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:14:44 by facetint          #+#    #+#             */
/*   Updated: 2024/08/11 15:55:43 by zeatilga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/config.h"
#include "../../includes/defines.h"
#include "../../get_next_line/get_next_line.h"

void	set_spawn_position(t_map *map, char c, int x, int y)
{
	if (c == 'N')
		map->spawn_direction = NORTH;
	else if (c == 'S')
		map->spawn_direction = SOUTH;
	else if (c == 'W')
		map->spawn_direction = WEST;
	else if (c == 'E')
		map->spawn_direction = EAST;
	else
		return ;
	if (map->spawn_point.x != -1 || map->spawn_point.y != -1)
		error_exit(MULTIPLE_SPAWN_POINTS);
	map->spawn_point = (t_vector){x + 0.5, y + 0.5};
}

void	get_map_data(int fd, void *arg)
{
	unsigned int	y;
	unsigned int	x;
	char			*line;
	t_map			*map;

	map = (t_map *)arg;
	y = -1;
	map->map = ft_calloc(map->height, sizeof(t_map_element **));
	while (++y < (unsigned int)map->height)
	{
		x = -1;
		line = get_next_line(fd);
		if (line == NULL)
			error_exit(READ_ERROR);
		map->map[y] = ft_calloc(map->width, sizeof(t_map_element *));
		while (++x < (unsigned int)map->width)
			set_position_and_fill_map(map, line, x, y);
	}
}

void	set_position_and_fill_map(
		t_map*map, char*line, unsigned int x, unsigned int y)
{
	unsigned int	len;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		len--;
	if (len > x)
	{
		set_spawn_position(map, line[x], x, y);
		map->map[y][x] = char_to_element(line[x]);
	}
	else
		map->map[y][x] = UNDEFINED;
}

t_map_element	char_to_element(char c)
{
	if (c == '1')
		return (WALL);
	if (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (EMPTY);
	if (c == ' ')
		return (UNDEFINED);
	error_exit(INVALID_CHARACTER);
	return (0);
}

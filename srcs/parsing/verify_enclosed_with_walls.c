/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_enclosed_with_walls.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeatilga <zeatilga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:14:40 by facetint          #+#    #+#             */
/*   Updated: 2024/08/11 15:48:46 by zeatilga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/config.h"
#include "../../includes/defines.h"

void	verify_enclosed_with_walls(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (get_map_element(*map, (t_coord){x, y}) == EMPTY &&
				!is_surrounded_by_defined(map, x, y))
				error_exit(MAP_NOT_SURROUNDED_BY_WALL);
			x++;
		}
		y++;
	}
}

int	is_surrounded_by_defined(t_map *map, int x, int y)
{
	return (get_map_element(*map, (t_coord){x, y + 1}) != UNDEFINED &&
	get_map_element(*map, (t_coord){x, y - 1}) != UNDEFINED &&
	get_map_element(*map, (t_coord){x + 1, y}) != UNDEFINED &&
	get_map_element(*map, (t_coord){x - 1, y}) != UNDEFINED);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeatilga <zeatilga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:15:07 by facetint          #+#    #+#             */
/*   Updated: 2024/08/10 20:42:43 by zeatilga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/config.h"
#include "../../includes/defines.h"
#include "../../safe_alloc/allocator.h"

int	is_in_bounds(t_map map, t_coord coord)
{
	return (coord.x >= 0 && coord.x < map.width
		&& coord.y >= 0 && coord.y < map.height);
}

t_map_element	get_map_element(t_map map, t_coord coord)
{
	if (!is_in_bounds(map, coord))
		return (UNDEFINED);
	return (map.map[coord.y][coord.x]);
}

void	set_map_element(t_map map, t_coord coord, t_map_element element)
{
	if (!is_in_bounds(map, coord))
		return ;
	map.map[coord.y][coord.x] = element;
}

void	free_map(t_map map)
{
	int	i;

	i = 0;
	while (i < map.height)
	{
		safe_free(map.map[i]);
		i++;
	}
	safe_free(map.map);
}

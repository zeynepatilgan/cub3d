/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeatilga <zeatilga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:12:52 by facetint          #+#    #+#             */
/*   Updated: 2024/08/10 20:47:38 by zeatilga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/config.h"
#include <math.h>

double	move_x(t_player *player, double delta)
{
	double			new_x;
	t_coord			target;
	t_map_element	element;

	new_x = player->position.x + delta * MOVEMENT_SPEED;
	target = (t_coord){(int)new_x, (int)player->position.y};
	element = get_map_element(player->map, target);
	if (element != WALL)
		return (new_x);
	return (player->position.x);
}

double	move_y(t_player *player, double delta)
{
	double			new_y;
	t_coord			target;
	t_map_element	element;

	new_y = player->position.y + delta * MOVEMENT_SPEED;
	target = (t_coord){(int)player->position.x,
		(int)(new_y + copysign(COLLISION_TOLERANCE, delta))};
	element = get_map_element(player->map, target);
	if (element != WALL)
		return (new_y);
	return (player->position.y);
}

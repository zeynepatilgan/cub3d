/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeatilga <zeatilga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 17:31:42 by facetint          #+#    #+#             */
/*   Updated: 2024/08/03 19:25:41 by zeatilga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/config.h"
#include <math.h>

void	rotate_player(t_player *player, double clock_dir)
{
	double		old_dir_x;
	double		old_plane_x;
	double		sinr;
	double		cosr;

	sinr = sin(ROTATION_SPEED * clock_dir);
	cosr = cos(ROTATION_SPEED * clock_dir);
	old_dir_x = player->camera.dir.x;
	player->camera.dir.x
		= player->camera.dir.x * cosr - player->camera.dir.y * sinr;
	player->camera.dir.y
		= old_dir_x * sinr + player->camera.dir.y * cosr;
	old_plane_x = player->camera.plane.x;
	player->camera.plane.x
		= player->camera.plane.x * cosr - player->camera.plane.y * sinr;
	player->camera.plane.y
		= old_plane_x * sinr + player->camera.plane.y * cosr;
}

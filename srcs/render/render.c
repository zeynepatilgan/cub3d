/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeatilga <zeatilga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:18:01 by facetint          #+#    #+#             */
/*   Updated: 2024/08/10 20:35:30 by zeatilga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minilibx/mlx.h"
#include "../../includes/render.h"
#include <math.h>

int	render_map(t_player	player)
{
	int			x;
	t_raycast	ray;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		calc_ray_direction(player, &ray, x);
		ray.gridcoord
			= (t_coord){(int)player.position.x, (int)player.position.y};
		ray.delta_dist.x = fabs(1 / ray.ray_dir.x);
		ray.delta_dist.y = fabs(1 / ray.ray_dir.y);
		calc_ray_step_side_dist(player, &ray);
		send_ray(player.map, &ray);
		calc_line_textures(player, player.map.texture, &ray);
		draw_line(&player.frame, player.map.texture, x, &ray);
		x++;
	}
	mlx_put_image_to_window
		(player.mlx.mlx, player.mlx.win, player.frame.img, 0, 0);
	return (0);
}

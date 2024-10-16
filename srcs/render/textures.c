/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeatilga <zeatilga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 18:33:11 by facetint          #+#    #+#             */
/*   Updated: 2024/08/10 20:34:10 by zeatilga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"
#include <math.h>

double	fract(double x)
{
	return (fabs(x - floor(x)));
}

void	calc_line_textures(
	t_player player, t_texture_data textures, t_raycast *ray)
{
	if (get_map_element(player.map, ray->gridcoord) != WALL)
	{
		ray->line_height = 0;
		return ;
	}
	calc_wall_dist(ray);
	calc_wall_texture_dimensions(textures, ray);
	ray->line_height = (int)(SCREEN_HEIGHT / ray->wall_dist);
	calc_texture(player, ray);
}

void	calc_wall_texture_dimensions(t_texture_data textures, t_raycast *ray)
{
	t_image	wall_img;

	if (ray->on_horizontal_line)
	{
		if (ray->ray_dir.y < 0)
			wall_img = textures.north;
		else
			wall_img = textures.south;
	}
	else
	{
		if (ray->ray_dir.x < 0)
			wall_img = textures.west;
		else
			wall_img = textures.east;
	}
	ray->current_texture.width = wall_img.width;
	ray->current_texture.height = wall_img.height;
}

void	calc_texture(t_player player, t_raycast *ray)
{
	double	wall_x;

	if (ray->on_horizontal_line)
		wall_x = fract(player.position.x + ray->wall_dist * ray->ray_dir.x);
	else
		wall_x = fract(player.position.y + ray->wall_dist * ray->ray_dir.y);
	ray->texture.x = (int)(wall_x * (double)ray->current_texture.width);
	if ((!ray->on_horizontal_line && ray->ray_dir.x < 0)
		|| (ray->on_horizontal_line && ray->ray_dir.y > 0))
		ray->texture.x = ray->current_texture.width - ray->texture.x - 1;
	ray->step = (double) ray->current_texture.height / ray->line_height;
	if (SCREEN_HEIGHT > ray->line_height)
		ray->texture.pos = 0;
	else
		ray->texture.pos = (ray->line_height - SCREEN_HEIGHT) * ray->step / 2;
}

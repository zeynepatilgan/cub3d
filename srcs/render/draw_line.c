/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeatilga <zeatilga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:17:50 by facetint          #+#    #+#             */
/*   Updated: 2024/08/10 20:36:05 by zeatilga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/config.h"
#include <math.h>

static int	get_texture_color(t_texture_data textures, t_raycast *ray)
{
	t_image	texture;
	int		color;

	if (ray->on_horizontal_line && ray->ray_dir.y < 0)
		texture = textures.north;
	else if (ray->on_horizontal_line && ray->ray_dir.y >= 0)
		texture = textures.south;
	else if (!ray->on_horizontal_line && ray->ray_dir.x < 0)
		texture = textures.west;
	else if (!ray->on_horizontal_line && ray->ray_dir.x >= 0)
		texture = textures.east;
	color = get_pixel(&texture, ray->texture.x, ray->texture.y);
	return (color);
}

void	draw_line(t_image *img, t_texture_data textures, int x, t_raycast *ray)
{
	int		y;
	int		color;
	double	draw_start;
	double	draw_end;

	draw_start = fmax(0, (SCREEN_HEIGHT - ray->line_height) / 2);
	draw_end = fmin(SCREEN_HEIGHT, (ray->line_height + SCREEN_HEIGHT) / 2);
	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		if (y < draw_start)
			set_pixel(img, x, y, textures.ceiling_color);
		else if (y >= draw_end)
			set_pixel(img, x, y, textures.floor_color);
		else
		{
			ray->texture.y = (int)ray->texture.pos;
			color = get_texture_color(textures, ray);
			ray->texture.pos += ray->step;
			set_pixel(img, x, y, color);
		}
		y++;
	}
}

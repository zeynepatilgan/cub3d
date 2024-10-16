/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeatilga <zeatilga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 18:29:11 by facetint          #+#    #+#             */
/*   Updated: 2024/08/10 20:10:54 by zeatilga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "config.h"   
# include "vector.h"

void	calc_ray_direction(t_player player, t_raycast *ray, int x);
void	calc_ray_step_side_dist(t_player player, t_raycast *ray);
void	calc_line_textures(t_player player, t_texture_data textures,
			t_raycast *ray);
void	send_ray(t_map map, t_raycast *ray);
void	calc_texture(t_player player, t_raycast *ray);
void	calc_wall_dist(t_raycast *ray);
void	draw_line(t_image *img, t_texture_data textures, int x, t_raycast *ray);
void	calc_wall_texture_dimensions(t_texture_data textures, t_raycast *ray);
void	send_ray(t_map map, t_raycast *ray);
int		render_map(t_player player);

double	fract(double x);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeatilga <zeatilga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:13:01 by facetint          #+#    #+#             */
/*   Updated: 2024/08/10 20:46:52 by zeatilga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minilibx/mlx.h"
#include "../../includes/config.h"
#include "../../safe_alloc/allocator.h"
#include <stdlib.h>

t_player	*get_player(void)
{
	static t_player	player = {0};

	return (&player);
}

void	free_all(t_player *player)
{
	if (!player->mlx.mlx)
		return ;
	if (player->mlx.win)
		mlx_destroy_window(player->mlx.mlx, player->mlx.win);
	if (player->frame.img)
		mlx_destroy_image(player->mlx.mlx, player->frame.img);
	if (player->map.texture.east.img)
		mlx_destroy_image(player->mlx.mlx, player->map.texture.east.img);
	if (player->map.texture.north.img)
		mlx_destroy_image(player->mlx.mlx, player->map.texture.north.img);
	if (player->map.texture.south.img)
		mlx_destroy_image(player->mlx.mlx, player->map.texture.south.img);
	if (player->map.texture.west.img)
		mlx_destroy_image(player->mlx.mlx, player->map.texture.west.img);
	free_memory();
}

void	handle_abort(void)
{
	free_all(get_player());
}

void	safe_exit(void)
{
	handle_abort();
	exit(0);
}

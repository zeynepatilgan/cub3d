/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeatilga <zeatilga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:18:06 by facetint          #+#    #+#             */
/*   Updated: 2024/08/11 16:56:06 by zeatilga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/defines.h"
#include "minilibx/mlx.h"
#include "includes/render.h"
#include <stdio.h>

int	close_window(void)
{
	safe_exit();
	return (0);
}

int	game_loop(t_player *player)
{
	if (player->keys->a)
	{
		player->position.x = move_x(player, -player->camera.plane.x);
		player->position.y = move_y(player, -player->camera.plane.y);
	}
	if (player->keys->d)
	{
		player->position.x = move_x(player, player->camera.plane.x);
		player->position.y = move_y(player, player->camera.plane.y);
	}
	if (player->keys->w)
	{
		player->position.x = move_x(player, player->camera.dir.x);
		player->position.y = move_y(player, player->camera.dir.y);
	}
	if (player->keys->s)
	{
		player->position.x = move_x(player, -player->camera.dir.x);
		player->position.y = move_y(player, -player->camera.dir.y);
	}
	if (player->keys->right_arrow)
		rotate_player(player, 1);
	if (player->keys->left_arrow)
		rotate_player(player, -1);
	return (render_map(*player));
}

void	set_player_camera(t_player *player)
{
	if (player->map.spawn_direction == NORTH)
	{
		player->camera.dir = (t_vector){0, -1};
		player->camera.plane = (t_vector){0.66, 0};
	}
	else if (player->map.spawn_direction == SOUTH)
	{
		player->camera.dir = (t_vector){0, 1};
		player->camera.plane = (t_vector){-0.66, 0};
	}
	else if (player->map.spawn_direction == WEST)
	{
		player->camera.dir = (t_vector){-1, 0};
		player->camera.plane = (t_vector){0, -0.66};
	}
	else if (player->map.spawn_direction == EAST)
	{
		player->camera.dir = (t_vector){1, 0};
		player->camera.plane = (t_vector){0, 0.66};
	}
}

int	main(int ac, char **av)
{
	t_mlx			mlx;
	t_player		*player;

	player = get_player();
	if (ac != 2)
		return (error_exit(WRONG_ARGS), 1);
	player->map = create_map(&mlx, av[1]);
	player->mlx = mlx;
	player->mlx.win = mlx_new_window(player->mlx.mlx,
			SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d by facetint&zeatilga");
	if (!player->mlx.win)
		error_exit("failed to open window\n");
	player->keys = &(t_pressed_keys){0};
	player->position = player->map.spawn_point;
	set_player_camera(get_player());
	printf("Player position: %f, %f\n", player->position.x, player->position.y);
	player->frame = create_img(player->mlx, SCREEN_HEIGHT, SCREEN_WIDTH);
	mlx_hook(player->mlx.win, 2, 0, key_press, player);
	mlx_hook(player->mlx.win, 3, 0, key_release, player);
	mlx_loop_hook(player->mlx.mlx, game_loop, player);
	mlx_hook(player->mlx.win, 17, 0, close_window, 0);
	mlx_loop(player->mlx.mlx);
}

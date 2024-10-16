/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeatilga <zeatilga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 17:39:25 by facetint          #+#    #+#             */
/*   Updated: 2024/08/10 20:47:21 by zeatilga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/config.h"

int	key_press(int key, t_player *player)
{
	if (key == ESC)
		safe_exit();
	if (key == A)
		player->keys->a = 1;
	else if (key == D)
		player->keys->d = 1;
	else if (key == W)
		player->keys->w = 1;
	else if (key == S)
		player->keys->s = 1;
	else if (key == LEFT_ARROW)
		player->keys->left_arrow = 1;
	else if (key == RIGHT_ARROW)
		player->keys->right_arrow = 1;
	return (0);
}

int	key_release(int key, t_player *player)
{
	if (key == A)
		player->keys->a = 0;
	else if (key == D)
		player->keys->d = 0;
	else if (key == W)
		player->keys->w = 0;
	else if (key == S)
		player->keys->s = 0;
	else if (key == LEFT_ARROW)
		player->keys->left_arrow = 0;
	else if (key == RIGHT_ARROW)
		player->keys->right_arrow = 0;
	return (0);
}

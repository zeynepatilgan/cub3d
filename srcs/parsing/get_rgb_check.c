/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeatilga <zeatilga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:14:58 by facetint          #+#    #+#             */
/*   Updated: 2024/08/11 15:54:59 by zeatilga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/config.h"
#include "../../includes/defines.h"
#include "../../safe_alloc/allocator.h"

char	**split_and_trim(char *str, char c)
{
	char	**split;
	char	*temp;
	int		i;

	i = 0;
	split = ft_split(str, c);
	if (split == NULL)
		error_exit(SAFE_MALLOC_ERROR);
	while (split[i] != NULL)
	{
		temp = ft_strtrim(split[i], " ");
		if (split[i] == NULL)
			error_exit(SAFE_MALLOC_ERROR);
		safe_free(split[i]);
		split[i] = temp;
		i++;
	}
	return (split);
}

int	str2rgb(char *str)
{
	int		r;
	int		g;
	int		b;
	char	**rgb;
	int		i;

	i = 0;
	rgb = split_and_trim(str, ',');
	if (rgb == NULL)
		error_exit(SAFE_MALLOC_ERROR);
	if (rgb[0] == NULL || rgb[1] == NULL || rgb[2] == NULL || rgb[3] != NULL)
		error_exit(INVALID_RGB);
	r = n_atoi(rgb[0]);
	g = n_atoi(rgb[1]);
	b = n_atoi(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		error_exit(INVALID_RGB);
	while (i < 3)
		safe_free(rgb[i++]);
	safe_free(rgb);
	return (r << 16 | g << 8 | b);
}

void	ensure_metadata_unset_(t_map_metadata meta)
{
	if (meta.floor_color == -1 && meta.ceiling_color == -1)
		error_exit("Floor and ceiling colors not set\n");
	if (meta.floor_color == -1)
		error_exit("Floor color not set\n");
	if (meta.ceiling_color == -1)
		error_exit("Ceiling color not set\n");
}

void	ensure_metadata_unset(t_map_metadata meta)
{
	ensure_metadata_unset_(meta);
	if (!meta.north_texture_file_name && !meta.south_texture_file_name
		&& !meta.west_texture_file_name && !meta.east_texture_file_name)
		error_exit("Textures not set\n");
	if (meta.north_texture_file_name == NULL)
		error_exit("North texture not set\n");
	if (meta.south_texture_file_name == NULL)
		error_exit("South texture not set\n");
	if (meta.west_texture_file_name == NULL)
		error_exit("West texture not set\n");
	if (meta.east_texture_file_name == NULL)
		error_exit("East texture not set\n");
}

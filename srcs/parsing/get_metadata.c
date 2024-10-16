/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_metadata.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeatilga <zeatilga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:15:03 by facetint          #+#    #+#             */
/*   Updated: 2024/08/11 15:56:08 by zeatilga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/config.h"
#include "../../includes/defines.h"
#include "../../get_next_line/get_next_line.h"
#include "../../safe_alloc/allocator.h"

void	get_metadata(int fd, void *arg)
{
	char			*line;
	int				line_count;
	t_map_metadata	*meta;

	line_count = 1;
	meta = (t_map_metadata *)arg;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (is_a_map_line(line))
		{
			meta->map_content_first_line = line_count;
			safe_free(line);
			return ;
		}
		read_metadata_from_line(meta, ft_strtrim(line, " "));
		safe_free(line);
		line_count++;
	}
}

int	is_a_map_line(char *line)
{
	int	element_found;

	element_found = 0;
	while (*line && *line != '\n')
	{
		if (*line != ' ' && *line != '1' && *line != '0' && *line != 'N'
			&& *line != 'S' && *line != 'W' && *line != 'E')
			return (0);
		if (*line != ' ')
			element_found = 1;
		line++;
	}
	return (element_found);
}

void	safe_set_value(char **ptr, char *value)
{
	if (*ptr != NULL)
		error_exit(DUPLICATE);
	*ptr = ft_strdup(value);
}

void	set_metadata(t_map_metadata *metadata, char *key, char *val)
{
	if (ft_strncmp(key, "NO", 2) == 0)
		safe_set_value(&metadata->north_texture_file_name, val);
	else if (ft_strncmp(key, "SO", 2) == 0)
		safe_set_value(&metadata->south_texture_file_name, val);
	else if (ft_strncmp(key, "WE", 2) == 0)
		safe_set_value(&metadata->west_texture_file_name, val);
	else if (ft_strncmp(key, "EA", 2) == 0)
		safe_set_value(&metadata->east_texture_file_name, val);
	else if (ft_strncmp(key, "F", 1) == 0)
	{
		if (metadata->floor_color != -1 || ft_strlen(key) != 1)
			error_exit(DUPLICATE_OR_TOO_LONG);
		metadata->floor_color = str2rgb(val);
	}
	else if (ft_strncmp(key, "C", 1) == 0)
	{
		if (metadata->ceiling_color != -1 || ft_strlen(key) != 1)
			error_exit(DUPLICATE_OR_TOO_LONG);
		metadata->ceiling_color = str2rgb(val);
	}
	else
		error_exit(INVALID_METADATA_ID_LENGTH);
}

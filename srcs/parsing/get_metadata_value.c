/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_metadata_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeatilga <zeatilga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:08:08 by zeatilga          #+#    #+#             */
/*   Updated: 2024/08/11 15:49:30 by zeatilga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/config.h"
#include "../../includes/defines.h"
#include "../../safe_alloc/allocator.h"

void	read_metadata_from_line(t_map_metadata *metadata, char *line)
{
	int		id_length;
	char	*value;
	char	*key;

	if (line[0] != '\n' && line[0] != '\0')
	{
		id_length = 0;
		while (line[id_length] != '\0'
			&& line[id_length] != '\n' && line[id_length] != ' '
			&& line[id_length] != '\t')
			id_length++;
		if (id_length != 1 && id_length != 2)
			error_exit(LONG_METADATA_KEY);
		value = ft_strtrim(line + id_length, " \n");
		get_metadata_value(value);
		key = ft_substr(line, 0, id_length);
		set_metadata(metadata, key, value);
		safe_free(key);
		safe_free(value);
	}
	safe_free(line);
}

void	get_metadata_value(char *value)
{
	int	i;

	i = -1;
	while (value[++i])
	{
		if (value[i] && value[i] == '/' && value[i + 1] == '/')
			error_exit(INVALID_METADATA_ID_LENGTH);
	}
	i = -1;
	while (value[++i])
	{
		if (value[i] && value[i] == '.' && value[i + 1] == '.'
			&& value[i - 1] != '/')
			error_exit(INVALID_METADATA_ID_LENGTH);
		if (value[i] && value[i] == '.' && value[i + 1] != '/'
			&& value[i - 1] == '.')
			error_exit(INVALID_METADATA_ID_LENGTH);
		if (value[i] && value[i] == '.' && value[i + 1] == '/'
			&& value[i - 1] == '/')
			error_exit(INVALID_METADATA_ID_LENGTH);
	}
}

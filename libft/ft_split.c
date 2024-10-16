/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeatilga <zeatilga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:16:29 by facetint          #+#    #+#             */
/*   Updated: 2024/08/10 20:43:58 by zeatilga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../safe_alloc/allocator.h"
#include "../includes/defines.h"
#include "../includes/config.h"

static int	count_words(char const *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (str[0] == c)
		error_exit(INVALID_RGB);
	while (str[i])
	{
		while (str[i] && str[i] == c)
		{
			if (str[i] && str[i] == c && str[i + 1] == c)
				error_exit(INVALID_RGB);
			if (str[i + 1] == '\0' && str[i] == c)
				error_exit(INVALID_RGB);
			i++;
		}
		if (str[i])
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

static int	word_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**free_arr(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		safe_free(result[i]);
		i++;
	}
	safe_free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char			**val;
	unsigned int	j;
	unsigned int	a;

	val = (char **)safe_malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!val)
		return (NULL);
	a = -1;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			val[++a] = (char *)safe_malloc((word_len(s, c) + 1) * sizeof(char));
			if (!val[a])
				return (free_arr(val));
			j = 0;
			while (*s && *s != c)
				val[a][j++] = *s++;
			val[a][j] = '\0';
		}
	}
	val[++a] = NULL;
	return (val);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:06:52 by facetint          #+#    #+#             */
/*   Updated: 2024/08/03 17:23:47 by facetint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../safe_alloc/allocator.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret_val;

	ret_val = (void *) safe_malloc(size * count);
	if (!ret_val)
		return (NULL);
	ft_bzero(ret_val, count * size);
	return (ret_val);
}

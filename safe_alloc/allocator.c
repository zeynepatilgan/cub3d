/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:15:22 by facetint          #+#    #+#             */
/*   Updated: 2024/07/30 20:16:15 by facetint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "allocator.h"
#define GOOD_EXIT 1
#define BAD_EXIT  0

t_memory_block	*get_memory_blocks(void)
{
	static t_memory_block	memory_blocks = {NULL, NULL};

	return (&memory_blocks);
}

int	append_memory_block(void *ptr)
{
	t_memory_block	*memory_blocks;
	t_memory_block	*new;

	if (!ptr)
		return (BAD_EXIT);
	new = malloc(sizeof(t_memory_block));
	if (!new)
		return (BAD_EXIT);
	*new = (t_memory_block){.ptr = ptr, .next = NULL};
	memory_blocks = get_memory_blocks();
	while (memory_blocks->next != NULL)
		memory_blocks = memory_blocks->next;
	memory_blocks->next = new;
	return (GOOD_EXIT);
}

int	remove_memory_block(void *ptr)
{
	t_memory_block	*cur;
	t_memory_block	*prev;

	if (!ptr)
		return (BAD_EXIT);
	cur = get_memory_blocks();
	while (cur != NULL)
	{
		if (cur->ptr == ptr)
		{
			prev->next = cur->next;
			free(cur);
			return (GOOD_EXIT);
		}
		prev = cur;
		cur = cur->next;
	}
	return (BAD_EXIT);
}

void	*safe_malloc(int size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		abort_memory();
		return (NULL);
	}
	if (!append_memory_block(ptr))
	{
		free(ptr);
		abort_memory();
		return (NULL);
	}
	return (ptr);
}

void	safe_free(void *ptr)
{
	if (!ptr)
		return ;
	remove_memory_block(ptr);
	free(ptr);
}

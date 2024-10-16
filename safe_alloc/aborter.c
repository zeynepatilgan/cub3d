/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aborter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:15:17 by facetint          #+#    #+#             */
/*   Updated: 2024/07/30 20:15:52 by facetint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "allocator.h"
#include <stdlib.h>

void	free_memory(void)
{
	t_memory_block	*memory_blocks;
	t_memory_block	*next;

	memory_blocks = get_memory_blocks()->next;
	while (memory_blocks != NULL)
	{
		next = memory_blocks->next;
		free(memory_blocks->ptr);
		free(memory_blocks);
		memory_blocks = next;
	}
	get_memory_blocks()->next = NULL;
}

void	abort_memory(void)
{
	register_pre_abort_func(NULL);
	free_memory();
	register_post_abort_func(NULL);
}

void	register_pre_abort_func(void (*abort_func)(void))
{
	static void	(*func)(void) = NULL;

	if (abort_func != NULL)
		func = abort_func;
	else if (func != NULL)
		func();
}

void	register_post_abort_func(void (*abort_func)(void))
{
	static void	(*func)(void) = NULL;

	if (abort_func != NULL)
		func = abort_func;
	else if (func != NULL)
		func();
}

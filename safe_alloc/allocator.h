/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:15:25 by facetint          #+#    #+#             */
/*   Updated: 2024/07/30 20:15:31 by facetint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOCATOR_H
# define ALLOCATOR_H

typedef struct s_memory_block
{
	void					*ptr;
	struct s_memory_block	*next;
}	t_memory_block;

void			*safe_malloc(int size);
void			safe_free(void *ptr);
t_memory_block	*get_memory_blocks(void);
void			free_memory(void);
void			abort_memory(void);
void			register_pre_abort_func(void (*abort_func)(void));
void			register_post_abort_func(void (*abort_func)(void));

#endif

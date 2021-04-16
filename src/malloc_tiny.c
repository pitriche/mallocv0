/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_tiny.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre42 <pierre42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:24:44 by pitriche          #+#    #+#             */
/*   Updated: 2020/07/09 17:51:22 by pierre42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include "libft.h"

static t_ma_tiny	*new_page(void)
{
	t_ma_tiny	*tmp;

	if (!(tmp = malloc_alloc(sizeof(t_ma_tiny))))
		return (0);
	ft_bzero(tmp, sizeof(t_ma_tiny));
	tmp->mem_free = MEM_ELEM_TINY * TINY_SIZE;
	return (tmp);
}

void				*tiny_malloc(t_malloc *d, unsigned size)
{
	t_ma_tiny	*tmp;

	if (!d->tiny)
		if (!(d->tiny = new_page()))
			return (0);
	tmp = d->tiny;
	while (tmp->next && (tmp->mem_free < size || tmp->n_elem >= MAX_ELEM_TINY))
		tmp = tmp->next;
	if (!tmp->next && (tmp->mem_free < size || tmp->n_elem >= MAX_ELEM_TINY))
	{
		if (!(tmp->next = new_page()))
			return (0);
		tmp = tmp->next;
	}
	tmp->meta[tmp->n_elem].off = !tmp->n_elem ? 0 :
	(tmp->meta[tmp->n_elem - 1].off + tmp->meta[tmp->n_elem - 1].len);
	tmp->meta[tmp->n_elem].len = size;
	tmp->mem_free -= size;
	return (tmp->mem + tmp->meta[tmp->n_elem++].off);
}

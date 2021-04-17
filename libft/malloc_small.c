/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_small.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre42 <pierre42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:24:44 by pitriche          #+#    #+#             */
/*   Updated: 2020/07/09 17:51:28 by pierre42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include "libft.h"

static t_ma_smal	*new_page(void)
{
	t_ma_smal	*tmp;

	if (!(tmp = malloc_alloc(sizeof(t_ma_smal))))
		return (0);
	ft_bzero(tmp, sizeof(t_ma_smal));
	tmp->mem_free = MEM_ELEM_SMAL * SMAL_SIZE;
	return (tmp);
}

void				*small_malloc(t_malloc *d, unsigned size)
{
	t_ma_smal	*tmp;

	if (!d->smal)
		if (!(d->smal = new_page()))
			return (0);
	tmp = d->smal;
	while (tmp->next && (tmp->mem_free < size || tmp->n_elem >= MAX_ELEM_SMAL))
		tmp = tmp->next;
	if (!tmp->next && (tmp->mem_free < size || tmp->n_elem >= MAX_ELEM_SMAL))
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

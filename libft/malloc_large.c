/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_large.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre42 <pierre42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:24:44 by pitriche          #+#    #+#             */
/*   Updated: 2020/07/09 17:51:37 by pierre42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include "libft.h"

static t_ma_larg	*new_page(void)
{
	t_ma_larg	*tmp;

	if (!(tmp = malloc_alloc(sizeof(t_ma_larg))))
		return (0);
	ft_bzero(tmp, sizeof(t_ma_larg));
	return (tmp);
}

void	*large_malloc(t_malloc *d, size_t size)
{
	t_ma_larg	*tmp;

	if (!d->larg)
		if (!(d->larg = new_page()))
			return (0);
	tmp = d->larg;

	while (tmp->next && tmp->n_elem >= MAX_ELEM_LARG)
		tmp = tmp->next;
	if (!tmp->next && tmp->n_elem >= MAX_ELEM_LARG)
	{
		if (!(tmp->next = new_page()))
			return (0);
		tmp = tmp->next;
	}
	tmp->len[tmp->n_elem] = ((size - 1) / d->ps + 1) * d->ps;
	tmp->mem[tmp->n_elem] = malloc_alloc(tmp->len[tmp->n_elem]);
	return (tmp->mem[tmp->n_elem++]);	
}

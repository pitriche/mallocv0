/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre42 <pierre42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:24:44 by pitriche          #+#    #+#             */
/*   Updated: 2020/07/09 17:10:58 by pierre42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include "libft.h"

static int	small_page_free(t_ma_smal *tmp, unsigned off)
{
	unsigned i;

	i = 0;
	while (i < tmp->n_elem)
	{
		if (off == tmp->meta[i].off)
		{
			ft_memmove(tmp->meta + i, tmp->meta + i + 1, 
				(tmp->n_elem - i - 1) * sizeof(t_ma_bloc));
			if (i >= --tmp->n_elem && tmp->n_elem)
				tmp->mem_free = MEM_ELEM_SMAL * SMAL_SIZE -
				tmp->meta[tmp->n_elem - 1].off -
				tmp->meta[tmp->n_elem - 1].len;
			else if (!tmp->n_elem)
				tmp->mem_free = MEM_ELEM_SMAL * SMAL_SIZE;
			return (1);
		}
		i++;
	}
	return (0);
}

int	small_free(t_malloc *d, void *ptr)
{
	t_ma_smal	*tmp;
	t_ma_smal	**cur;
	unsigned	off;
	int			ret;

	tmp = d->smal;
	cur = &(d->smal);
	while (tmp)
	{
		off = ptr - (void *)tmp->mem;
		if (off >= 0 && off < MEM_ELEM_SMAL * SMAL_SIZE)
		{
			ret = small_page_free(tmp, off);
			if (!tmp->n_elem)
			{
				munmap(*cur, sizeof(t_ma_smal));
				*cur = 0;
			}
			return (ret);
		}
		cur = &tmp->next;
		tmp = tmp->next;
	}
	return (0);
}

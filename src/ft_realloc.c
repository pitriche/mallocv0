/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre42 <pierre42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:24:44 by pitriche          #+#    #+#             */
/*   Updated: 2020/07/09 18:57:27 by pierre42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include "libft.h"

static size_t	large_size(t_malloc	*d, void *ptr)
{
	t_ma_larg	*tmp;
	unsigned	i;

	tmp = d->larg;
	while (tmp)
	{
		i = -1;
		while (++i < tmp->n_elem)
			if (tmp->mem[i] == ptr)
				return (tmp->len[i]);
		tmp = tmp->next;
	}
	return (0);
}

static size_t	small_size(t_malloc	*d, void *ptr)
{
	t_ma_smal	*tmp;
	unsigned	off;
	unsigned	i;

	tmp = d->smal;
	while (tmp)
	{
		off = ptr - (void *)tmp->mem;
		if (off >= 0 && off < MEM_ELEM_SMAL * SMAL_SIZE)
		{
			i = -1;
			while (++i < tmp->n_elem)
				if (off == tmp->meta[i].off)
					return (tmp->meta[i].len);
		}
		tmp = tmp->next;
	}
	return (0);
}

static size_t	tiny_size(t_malloc	*d, void *ptr)
{
	t_ma_tiny	*tmp;
	unsigned	off;
	unsigned	i;

	tmp = d->tiny;
	while (tmp)
	{
		off = ptr - (void *)tmp->mem;
		if (off >= 0 && off < MEM_ELEM_TINY * TINY_SIZE)
		{
			i = -1;
			while (++i < tmp->n_elem)
				if (off == tmp->meta[i].off)
					return (tmp->meta[i].len);
		}
		tmp = tmp->next;
	}
	return (0);
}

void	*ft_realloc(void *ptr, size_t size)
{
	t_malloc	*d;
	void		*tmp;
	size_t		old;

	d = malloc_data();
	if (!ptr)
		return (ft_malloc(size));
	old = large_size(d, ptr);
	if (!old)
		old = small_size(d, ptr);
	if (!old)
		old = tiny_size(d, ptr);
	if (!old)
		return (ft_malloc(size));
	if (old == size)
		return (ptr);
	tmp = ft_malloc(size);
	ft_memcpy(tmp, ptr, old < size ? old : size);
	ft_free(ptr);
	return (tmp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre42 <pierre42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:24:44 by pitriche          #+#    #+#             */
/*   Updated: 2020/07/09 17:09:58 by pierre42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include "libft.h"

int	large_free(t_malloc *d, void *ptr)
{
	t_ma_larg	*tmp;
	t_ma_larg	**cur;
	unsigned	i;

	tmp = d->larg;
	cur = &d->larg;
	while (tmp)
	{
		i = 0;
		while (i < tmp->n_elem)
		{
			if (tmp->mem[i] == ptr)
			{
				munmap(ptr, tmp->len[i]);
				ft_memmove(tmp->mem + i, tmp->mem + i + 1, 
					(tmp->n_elem - i - 1) * sizeof(void *));
				ft_memmove(tmp->len + i, tmp->len + i + 1, 
					(tmp->n_elem - i - 1) * sizeof(size_t));
				if (!(--tmp->n_elem))
				{
					munmap(*cur, sizeof(t_ma_smal));
					*cur = 0;
				}
				return (1);
			}
			i++;
		}
		cur = &tmp->next;
		tmp = tmp->next;
	}
	return (0);
}

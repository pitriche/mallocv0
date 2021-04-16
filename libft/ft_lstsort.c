/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 16:54:28 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/19 17:28:29 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lst_issort(t_list *lst, int (*cmp)(void *, void *))
{
	int size;
	int nope;

	size = 1;
	nope = 1;
	while (lst->next)
	{
		if (cmp(lst->data, lst->next->data) > 0)
			nope = 0;
		size++;
		lst = lst->next;
	}
	return (nope ? 1 : size);
}

void		ft_lstsort(t_list *lst, int (*cmp)(void *, void *))
{
	t_list	*tmp;
	int		size;

	if (!lst)
		return ;
	if (!(size = lst_issort(lst, cmp)))
		return ;
	while (--size)
	{
		tmp = lst;
		while (tmp->next)
		{
			if (cmp(tmp->data, tmp->next->data) > 0)
				ft_swap(&(tmp->data), &(tmp->next->data));
			tmp = tmp->next;
		}
	}
}

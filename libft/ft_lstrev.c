/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 16:14:21 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/28 13:58:39 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrev(t_list **lst)
{
	t_list *prev;
	t_list *next;

	if (!(*lst))
		return ;
	if (!(*lst)->next)
		return ;
	if (!(*lst)->next->next)
	{
		(*lst)->next->next = *lst;
		(*lst) = (*lst)->next;
		(*lst)->next->next = 0;
		return ;
	}
	prev = *lst;
	*lst = (*lst)->next;
	prev->next = 0;
	next = (*lst)->next;
	while (next)
	{
		next = (*lst)->next;
		(*lst)->next = prev;
		prev = *(lst);
		next ? *(lst) = next : 0;
	}
}

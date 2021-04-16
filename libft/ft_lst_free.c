/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 18:18:01 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/20 18:20:05 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			ft_lst_free(t_list *lst)
{
	t_list *poi;

	while (lst)
	{
		poi = lst;
		lst = lst->next;
		free(poi);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_free_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 14:44:10 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/20 18:19:31 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			ft_lst_free_data(t_list *lst)
{
	t_list *poi;

	while (lst)
	{
		poi = lst;
		lst = lst->next;
		free(poi->data);
		free(poi);
	}
}

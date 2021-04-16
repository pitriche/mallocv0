/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 13:17:50 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/20 13:29:07 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_longlen(long nb)
{
	char			len;
	unsigned long	l;

	if (!nb)
		return (1);
	len = nb < 0 ? 2 : 1;
	l = nb < 0 ? -nb : nb;
	while (l /= 10)
		len++;
	return (len);
}

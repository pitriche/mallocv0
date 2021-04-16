/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltos_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_lltos_base
** convert a long long to a given base, then put it in a freshly allocated
** string. I swear to god if min long long is really 9223372036854775808 i an
** murdering the creator of mac os
** -
** takes a long long to convert, and a string containing the base
** return the freshly allocated string
*/

char	*ft_ulltos_base(unsigned long long nb, const char *base_c)
{
	int		base;
	char	*str;
	int		i;

	i = 0;
	if ((base = ft_strlen(base_c)) < 2 ||
	!(str = ft_strnew(64)))
		return (0);
	if (nb == 0)
		str[i++] = base_c[0];
	while (nb > 0)
	{
		str[i] = base_c[nb % base];
		nb /= base;
		i++;
	}
	return (ft_strrev(str));
}

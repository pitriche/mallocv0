/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	int i;

	i = 0;
	if (!*(char *)to_find || !to_find)
		return ((char *)str);
	if (!len)
		return (0);
	if (len < ft_strlen(to_find))
		return (0);
	len -= ft_strlen(to_find);
	while (str[i] && len-- + 1)
	{
		if (!ft_strncmp((char *)str + i, (char *)to_find, ft_strlen(to_find)))
			return ((char *)str + i);
		i++;
	}
	return (0);
}

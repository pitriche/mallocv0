/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *srcc, size_t size)
{
	char		*src;
	unsigned	nanodesu;

	src = (char *)srcc;
	if (size >= ft_strlen(dest))
		nanodesu = ft_strlen(dest) + ft_strlen(src);
	else
		return (ft_strlen(src) + size);
	while (*dest && size)
	{
		size--;
		dest++;
	}
	while (*src && size > 1)
	{
		*dest = *src;
		src++;
		dest++;
		size--;
	}
	*dest = 0;
	return (nanodesu);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy_bw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy_bw(char *dest, const char *src, size_t n)
{
	int i1;
	int i2;

	i1 = n - 1;
	i2 = n - 1;
	if (!src)
	{
		ft_bzero(dest, n);
		return (0);
	}
	while (n--)
		dest[i1--] = src[i2--];
	return (dest);
}

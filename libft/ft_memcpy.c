/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_memcpy
** copy n bytes from src to dest
** -
** takes a pointer to source and dest, and how much memory is to move
** return dest
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int i1;
	int i2;

	i1 = 0;
	i2 = 0;
	while (n--)
		*((unsigned char *)dest + i1++) = *((unsigned char *)src + i2++);
	return (dest);
}

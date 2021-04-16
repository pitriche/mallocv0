/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_memset
** fill n bytes of memory with c at the s adress
** -
** takes the adress to start padding, the filler c and the number of bytes to
** pad
** return nothing
*/

void	*ft_memset(void *ptr, int c, size_t n)
{
	int i;

	i = 0;
	while (n--)
	{
		*((unsigned char *)ptr + i) = (unsigned char)c;
		i++;
	}
	return (ptr);
}

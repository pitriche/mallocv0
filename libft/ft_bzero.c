/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/12/19 13:04:36 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_bzero  F 4 S T  A S  F U C C
** fill n bytes of memory with 0 at the s adress, but f4ster than my bullet
** -
** takes the adress to start padding and the number of bytes to pad
** return nothing
*/

void	ft_bzero(void *s, size_t n)
{
	while (n & 0b111)
	{
		n--;
		*((char *)s + n) = 0;
	}
	while (n >= 8)
	{
		n -= 8;
		*((long *)s + (n >> 3)) = 0;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strcpy
** copy a string in another
** -
** takes a destination string and a source string
** return dest
*/

char	*ft_strcpy(char *dest, const char *src)
{
	int i1;
	int i2;

	i1 = 0;
	i2 = 0;
	while (src[i2])
		dest[i1++] = src[i2++];
	dest[i1] = 0;
	return (dest);
}

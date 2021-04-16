/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strndup
** duplicates n chars of a string and put them on a freshly allocated null
** terminated string
** -
** takes a source string and the amount of chars to copy
** return the freshly allocated string
*/

char	*ft_strndup(const char *s, size_t n)
{
	char *tmp;

	if (ft_strlen(s) <= n)
		return (ft_strdup(s));
	if (!(tmp = ft_strnew(n)))
		return (0);
	ft_memcpy((void *)tmp, (void *)s, n);
	return (tmp);
}

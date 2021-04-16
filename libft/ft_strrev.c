/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** swappe
** mom
** -
** get
** the
** camera
*/

static void	swappe(char *p1, char *p2)
{
	char c;

	c = *p1;
	*p1 = *p2;
	*p2 = c;
}

/*
** ft_strrev
** reverse the string
** -
** takes a string to rev
** return the reversed string
*/

char		*ft_strrev(char *s)
{
	int i;
	int l;

	if (!s)
		return (0);
	i = 0;
	l = ft_strlen(s) - 1;
	while (i < l)
		swappe(s + i++, s + l--);
	return (s);
}

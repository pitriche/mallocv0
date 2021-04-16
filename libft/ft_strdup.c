/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** ft_strdup
** alocate a string of the right size then copy the argument's content in the
** new string
** -
** takes a string
** return a frecshly allocated string containing a copy of s
*/

char	*ft_strdup(const char *s)
{
	char *tmp;

	if (!(tmp = (char *)malloc(ft_strlen(s) + 1)))
		return (0);
	ft_strcpy(tmp, s);
	return (tmp);
}

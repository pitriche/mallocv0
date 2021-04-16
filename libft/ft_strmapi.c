/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 14:40:28 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*r;
	int		i1;
	int		i2;
	int		i;

	i = 0;
	i1 = 0;
	i2 = 0;
	if (!s)
		return (0);
	if (!(r = ft_strnew(ft_strlen(s))))
		return (0);
	while (s[i2])
		r[i1++] = f(i++, s[i2++]);
	r[i2] = 0;
	return (r);
}

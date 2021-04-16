/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strtrimlen(char const *s)
{
	int i;
	int i2;

	if (!s)
		return (0);
	i = 0;
	i2 = ft_strlen(s);
	while (ft_isspace(s[i]))
		i++;
	if (i == i2)
		return (0);
	while (ft_isspace(s[--i2]))
		;
	return (i2 - i + 1);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		i2;

	i = 0;
	if (!s)
		return (0);
	i2 = ft_strtrimlen(s);
	if (!(str = ft_strnew(i2)))
		return (0);
	while (ft_isspace(s[i]))
		i++;
	ft_strncpy(str, s + i, i2);
	return (str);
}

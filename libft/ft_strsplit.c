/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_nwords(char const *s, char c)
{
	long	i;
	int		b;
	int		nb;

	i = 0;
	b = 0;
	nb = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (b == 0)
				nb++;
			b = 1;
		}
		else
			b = 0;
		i++;
	}
	return (nb);
}

static char	**ft_split(char const *s, char c)
{
	long	i;
	long	j;
	int		x;
	int		nb;
	char	**tab;

	nb = ft_nwords(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (nb + 1))))
		return (0);
	i = 0;
	j = -1;
	while (++j < nb && s[i])
	{
		x = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i + x] != c && s[i + x])
			x++;
		tab[j] = ft_strsub(s, i, x);
		i = i + x;
	}
	tab[j] = 0;
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	if (s)
		return (ft_split(s, c));
	return (NULL);
}

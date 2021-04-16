/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	len(int n)
{
	int l;

	l = (n >= 0 ? 1 : 2);
	while (n > 9 || n < -9)
	{
		n /= 10;
		l++;
	}
	return (l);
}

static int	power(int size)
{
	int i;

	i = 1;
	while (size-- > 0)
		i *= 10;
	return (i);
}

static void	dew_it(char *str, int size, long n)
{
	n = n > 0 ? n : -n;
	while (size)
		*(str++) = n / power(--size) % 10 + '0';
	*str = 0;
}

char		*ft_itoa(int n)
{
	char *str;

	if (!(str = (char *)malloc(len(n) + 1)))
		return (0);
	if (n < 0)
		*str = '-';
	dew_it(str + (n < 0 ? 1 : 0), len(n) - (n < 0 ? 1 : 0), (long)n);
	return (str);
}

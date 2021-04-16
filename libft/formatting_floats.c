/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatting_floats.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:20 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

/*
** ld_round
** ldtos_prec portion, returns the decimal part of a long double
*/

static void	ld_round(t_arg *arg, char *ld_str)
{
	int i;
	int off;

	i = 0;
	off = 1;
	*ld_str == '-' ? ld_str++ : 0;
	while (ld_str[i++])
		if (ld_str[i - 1] != '9' && ld_str[i - 1] != '.' && !(!ld_str[i] &&
		ld_str[i - 1] >= '5'))
			off = 0;
	i--;
	if (ld_str[--i] >= '5')
	{
		ld_str[--i] != '.' ? ld_str[i]++ : ld_str[--i]++;
		while (ld_str[i] == ':')
		{
			ld_str[i] = '0';
			ld_str[i - 1] == '.' ? i-- : 0;
			i > 0 ? ld_str[--i]++ : 0;
		}
	}
	ld_str[ft_strlen(ld_str) - (arg->precision || arg->hash ? 1 : 2)] = 0;
	off ? ft_memmove(ld_str + 1, ld_str, ft_strlen(ld_str) + 1) : 0;
	off ? ld_str[0] = '1' : 0;
}

/*
** ld_int
** ldtos_prec portion, returns the integer part of a long double
*/

static char	*ld_int(long double nb)
{
	char	*str;
	int		sign;
	int		i;

	if (!(str = ft_strnew(MAX_EXPECTED_DIGITS)))
		return (0);
	sign = nb >= 0 ? 0 : 1;
	nb = nb >= 0 ? nb : -nb;
	if (nb < 1)
		*str = '0';
	else
	{
		i = 0;
		while (nb >= 1 && i <= MAX_EXPECTED_DIGITS)
		{
			str[i++] = (unsigned long long)nb % 10 + '0';
			nb /= 10;
		}
		ft_strrev(str);
	}
	sign ? ft_memmove(str + 1, str, ft_strlen(str)) : 0;
	sign ? *str = '-' : 0;
	return (str);
}

/*
** ld_dec
** ldtos_prec portion, returns the decimal part of a long double
*/

static char	*ld_dec(t_arg *arg, long double nb)
{
	char	*str;
	int		i;
	int		prec;

	prec = arg->precision;
	prec == -1 ? prec = DEFAULT_PREC : 0;
	prec++;
	if (!(str = ft_strnew(prec + 1)))
		return (0);
	i = 0;
	*str = '.';
	nb < 0 ? nb = -nb : 0;
	while (prec--)
	{
		nb *= 10;
		str[++i] = (unsigned long long)nb % 10 + '0';
	}
	return (str);
}

/*
** ldtos_prec
** outputs the base string for a floating point real number, with precision
** -
** takes a t_arg and a long double
** return the string, or 0 if a malloc fails
*/

char		*ldtos_prec(t_arg *arg, long double nb)
{
	char *str;
	char *dec_part;
	char *int_part;

	if (nb == (long double)(float)1954e100)
		return (ft_strdup("inf"));
	if (nb != nb)
		return (ft_strdup("nan"));
	if (!(dec_part = ld_dec(arg, nb)))
		return (0);
	if (!(int_part = ld_int(nb)))
		return (0);
	if (!(str = ft_strjoin_free(int_part, dec_part)))
		return (0);
	ld_round(arg, str);
	return (str);
}

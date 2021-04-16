/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatting_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

/*
** cspb_str
** flags_str portion to format chars, strings, percents and blanks
*/

static int	cspb_str(t_arg *arg, char **arg_str)
{
	int		len;
	char	pad;
	char	*str;

	len = ft_strlen(*arg_str);
	pad = arg->zero && !arg->minus ? '0' : ' ';
	str = *arg_str;
	if (arg->min_field <= len)
		return (1);
	if (!(*arg_str = ft_strnew(arg->min_field)))
		return (0);
	ft_memset(*arg_str, pad, arg->min_field);
	ft_memcpy(*arg_str + (arg->minus ? 0 : arg->min_field - len), str, len);
	!arg->type[2] ? (*arg_str)[arg->min_field - 1] = 0 : 0;
	free(str);
	return (1);
}

/*
** nb_prec [TESTED]
** flags_str portion to apply precision to numbers, except the floaty boi
*/

static int	nb_prec(t_arg *arg, char **arg_str)
{
	char	*str;
	char	minus;
	char	sign;
	int		len;

	str = *arg_str;
	len = ft_strlen(str);
	minus = *str == '-' ? 2 : 0;
	sign = !minus && (arg->plus || arg->space) ? 1 : 0;
	if (len - minus >= arg->precision && !(len == arg->precision && sign))
	{
		if (!sign)
			return (1);
		else
			arg->precision = len;
	}
	if (!(*arg_str = ft_strnew(arg->precision + (minus || sign))))
		return (0);
	ft_memcpy(*arg_str + arg->precision - len + (minus || sign), str, len);
	ft_memset(*arg_str, '0', arg->precision - len + minus + sign);
	minus ? **arg_str = '-' : 0;
	if (sign)
		**arg_str = arg->plus ? '+' : ' ';
	free(str);
	return (1);
}

/*
** diu_str [TESTED]
** flags_str portion to format integers, with that really pesky negative thingy
*/

static int	diu_str(t_arg *arg, char **arg_str)
{
	int		len;
	char	pad;
	char	sign;
	char	*str;

	if (!(nb_prec(arg, arg_str)))
		return (0);
	str = *arg_str;
	pad = arg->zero && !arg->minus ? '0' : ' ';
	len = ft_strlen(str);
	sign = ft_strchr(" -+", *str) ? *str : 0;
	if (arg->min_field <= len)
		return (1);
	if (!(*arg_str = ft_strnew(arg->min_field)))
		return (0);
	ft_memset(*arg_str, pad, arg->min_field);
	ft_memcpy(*arg_str + (arg->minus ? !!sign : arg->min_field - len + !!sign),
	str + !!sign, len - !!sign);
	sign && (pad == '0' || arg->minus) ? **arg_str = sign : 0;
	sign && pad == ' ' && !arg->minus ? *(*arg_str + arg->min_field - len) =
	sign : 0;
	free(str);
	return (1);
}

/*
** flags_str
** formats correctly the argument givem the flags, by tweaking the initial
** string
** -
** takes a t_arg and a pointer on the string to format
** return 1 if success, 0 if a malloc fails
*/

int			flags_str(t_arg *arg, char **arg_str)
{
	char c;

	c = arg->type[2];
	if (c == 'c' || c == '%' || c == 's' || !c)
		return (cspb_str(arg, arg_str));
	if (c == 'd' || c == 'i' || c == 'u' || c == 'f')
		return (diu_str(arg, arg_str));
	if (c == 'o' || c == 'x' || c == 'X')
		return (oxx_str(arg, arg_str));
	return (1);
}

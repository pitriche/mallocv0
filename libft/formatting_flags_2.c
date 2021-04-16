/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatting_flags_2.c                               :+:      :+:    :+:   */
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
** minus_hash
** because theres another particular case for negative fields with hash
*/

static int	minus_hash(t_arg *arg, char **arg_str)
{
	char	*str;
	int		len;
	int		trim;

	if (!arg->minus)
		return (1);
	str = *arg_str;
	len = ft_strlen(str);
	trim = str[len - 1] == ' ' ? 1 : 0;
	str[len - 2] == ' ' && arg->type[2] != 'o' ? trim = 2 : 0;
	if (!trim)
		return (1);
	if (!(*arg_str = ft_strnew(len - trim)))
		return (0);
	ft_strncpy(*arg_str, str, len - trim);
	free(str);
	return (1);
}

/*
** nb_uns_prec
** flags_str portion to apply precision to numbers, except the floaty boi. Also
** disable hash if number is 0
*/

static int	nb_uns_prec(t_arg *arg, char **arg_str)
{
	char	*str;
	int		len;

	str = *arg_str;
	if (((*str == '0' || arg->is_zero) && arg->type[2] != 'o') &&
	!arg->pointer)
		arg->hash = 0;
	len = ft_strlen(str);
	!arg->prec_ori && arg->is_zero && !arg->hash ? **arg_str = 0 : 0;
	if (len >= arg->precision)
		return (1);
	if (!(*arg_str = ft_strnew(arg->precision)))
		return (0);
	ft_memcpy(*arg_str + arg->precision - len, str, len);
	ft_memset(*arg_str, '0', arg->precision - len);
	free(str);
	return (1);
}

/*
** xX_hash
** oxX_str portion to add the special form of hex
*/

static int	xx_hash(t_arg *arg, char **arg_str)
{
	char	*str;
	int		offset;

	str = *arg_str;
	if (*str == '0' && str[1] == '0' && arg->zero)
	{
		str[1] = arg->type[2];
		return (1);
	}
	if (*str == ' ' && str[1] == ' ')
	{
		while (*(str + 2) == ' ')
			str++;
		str[0] = '0';
		str[1] = arg->type[2];
		return (1);
	}
	offset = *str == '0' && arg->zero && !arg->pointer ? 1 : 2;
	*str == ' ' ? offset = 1 : 0;
	if (!(*arg_str = ft_strnew(ft_strlen(str) + offset)))
		return (0);
	ft_strcpy(*arg_str + offset, str);
	ft_memcpy(*arg_str, arg->type[2] == 'x' ? "0x" : "0X", 2);
	free(str);
	return (1);
}

/*
** oxx_hash
** oxX_str portion to add the special form of octal, redirect if hex
** note: str is in the function's parameters because FUCK THE 25 LINES
*/

static int	oxx_hash(t_arg *arg, char **arg_str, char *str)
{
	if (!arg->hash)
		return (1);
	if (arg->type[2] != 'o')
	{
		if (!xx_hash(arg, arg_str))
			return (0);
		return (minus_hash(arg, arg_str));
	}
	if (*str == '0')
		return (1);
	if (*str == ' ')
	{
		while (*(str + 1) == ' ')
			str++;
		str[1] != '0' ? *str = '0' : 0;
		return (1);
	}
	if (!(*arg_str = ft_strnew(ft_strlen(str) + 1)))
		return (0);
	ft_strcpy(*arg_str + 1, str);
	**arg_str = '0';
	free(str);
	return (minus_hash(arg, arg_str));
}

/*
** oxX_str
** flags_str portion to format octal and hex, with that really pesky negative
** thingy
*/

int			oxx_str(t_arg *arg, char **arg_str)
{
	int		len;
	char	pad;
	char	*str;

	if (!(nb_uns_prec(arg, arg_str)))
		return (0);
	str = *arg_str;
	pad = arg->zero && !arg->minus ? '0' : ' ';
	len = ft_strlen(str);
	if (arg->min_field <= len)
	{
		if (arg->hash)
			if (!(oxx_hash(arg, arg_str, *arg_str)))
				return (0);
		return (1);
	}
	if (!(*arg_str = ft_strnew(arg->min_field)))
		return (0);
	ft_memset(*arg_str, pad, arg->min_field);
	ft_memcpy(*arg_str + (arg->minus ? 0 : arg->min_field - len), str, len);
	free(str);
	return (oxx_hash(arg, arg_str, *arg_str));
}

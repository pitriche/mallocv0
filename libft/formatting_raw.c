/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatting_raw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/04/19 17:14:54 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*
** s_base
** base string portion for strings
*/

static char	*s_base(t_arg *arg, va_list va)
{
	char *str_arg;

	str_arg = va_arg(va, char *);
	if (!str_arg)
		str_arg = "(null)";
	if (arg->precision == -1)
		return (ft_strdup(str_arg));
	return (ft_strndup(str_arg, arg->precision));
}

/*
** ouxXB_base
** base string portion for octal, unsigned decimal and low and cap hexadecimal
*/

static char	*ouxx_base(t_arg *arg, va_list va)
{
	const char			*base;
	unsigned long long	nb;

	nb = va_arg(va, unsigned long long);
	arg->is_zero = nb ? 0 : 1;
	arg->precision != -1 ? arg->zero = 0 : 0;
	!arg->precision && arg->type[2] == 'o' ? arg->precision++ : 0;
	if (!arg->precision && !nb)
		return (ft_strnew(0));
	arg->type[2] == 'o' ? base = "01234567" : 0;
	arg->type[2] == 'u' ? base = "0123456789" : 0;
	arg->type[2] == 'x' ? base = "0123456789abcdef" : 0;
	arg->type[2] == 'X' ? base = "0123456789ABCDEF" : 0;
	if (arg->type[0] == 'h' && arg->type[1] == 'h')
		return (ft_ulltos_base((unsigned char)nb, base));
	else if (arg->type[1] == 'h')
		return (ft_ulltos_base((unsigned short)nb, base));
	else if (arg->type[0] == 'l' && arg->type[1] == 'l')
		return (ft_ulltos_base(nb, base));
	else if (arg->type[1] == 'l')
		return (ft_ulltos_base((unsigned long)nb, base));
	else
		return (ft_ulltos_base((unsigned int)nb, base));
}

/*
** csp_blank_percent_base
** base string portion for chars, strings, pointers, percents, and unrecognized
** chars/blank chars. Call ouxX_base for pointers, and use precision flag to
** gather string if s is used and a precision is given
*/

static char	*csp_blank_percent_base(t_arg *arg, va_list va, t_printf *pr)
{
	char	*str;

	if (arg->type[2] == 'c' || arg->type[2] == '%')
	{
		if (!(str = ft_strnew(1)))
			return (0);
		str[0] = arg->type[2] == 'c' ? c_base(arg, va, pr) : '%';
		return (str);
	}
	else if (arg->type[2] == 'p')
	{
		arg->hash = 1;
		arg->type[1] = 'l';
		arg->type[2] = 'x';
		arg->pointer = 1;
		return (ouxx_base(arg, va));
	}
	else if (arg->type[2] == 's')
		return (s_base(arg, va));
	else
		return (ft_strnew(0));
}

/*
** difB_base
** base string portion for integers and floats, base can be specified
*/

static char	*difb_base(t_arg *arg, va_list va)
{
	const char			*base;
	signed long long	nb;

	base = arg->type[2] == 'B' ? va_arg(va, char *) : "0123456789";
	nb = va_arg(va, signed long long);
	arg->precision != -1 ? arg->zero = 0 : 0;
	if (!arg->precision && !nb && arg->type[2] != 'f')
		return (ft_strnew(0));
	if (arg->type[0] == 'h' && arg->type[1] == 'h' && arg->type[2] != 'f')
		return (ft_lltos_base((signed char)nb, base));
	else if (arg->type[1] == 'h' && arg->type[2] != 'f')
		return (ft_lltos_base((short)nb, base));
	else if (arg->type[1] == 'l' && arg->type[2] != 'f')
		return (ft_lltos_base((long)nb, base));
	else if (arg->type[0] == 'l' && arg->type[1] == 'l' && arg->type[2] != 'f')
		return (ft_lltos_base((long long)nb, base));
	else if (arg->type[2] == 'f' && arg->type[1] == 'L')
		return (ldtos_prec(arg, va_arg(va, long double)));
	else if (arg->type[2] == 'f')
		return (ldtos_prec(arg, (long double)va_arg(va, double)));
	else
		return (ft_lltos_base((int)nb, base));
}

/*
** base_str
** gets the unformatted output of the argument, by selecting the right type and
** the right conversion depending on arg. Also removes the wrong flags from the
** arg
** -
** takes a t_arg and a list with the argument
** return the raw string
*/

char		*base_str(t_arg *arg, va_list va, t_printf *pr)
{
	char c;

	c = arg->type[2];
	arg->minus ? arg->zero = 0 : 0;
	if (c == 'd' || c == 'i' || c == 'f' || c == 'B')
		return (difb_base(arg, va));
	else if (c == 'o' || c == 'u' || c == 'x' || c == 'X')
		return (ouxx_base(arg, va));
	else
		return (csp_blank_percent_base(arg, va, pr));
}

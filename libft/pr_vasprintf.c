/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:27:37 by pitriche          #+#    #+#             */
/*   Updated: 2019/04/19 17:14:54 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>

/*
** parse_nbr
** parse_arg portion that retrieve a number
*/

static int	parse_nbr(char **format)
{
	int nb;

	nb = 0;
	**format == '.' ? (*format)++ : 0;
	while (ft_strchr("0123456789", **format))
	{
		nb = nb * 10 + **format - '0';
		(*format)++;
	}
	(*format)--;
	return (nb);
}

/*
** parse_flags
** parse_arg portion that proceed to retrieve the flags
*/

static void	parse_flags(char **format, t_arg *arg, va_list va)
{
	while (ft_strchr("#+- *$.0123456789lhL", **format) && **format)
	{
		**format == '#' ? arg->hash = 1 : 0;
		**format == '-' ? arg->minus = 1 : 0;
		**format == '+' ? arg->plus = 1 : 0;
		**format == '0' ? arg->zero = 1 : 0;
		**format == ' ' ? arg->space = 1 : 0;
		**format == '*' ? arg->precision = va_arg(va, int) : 0;
		**format == '$' ? arg->min_field = va_arg(va, int) : 0;
		ft_strchr("123456789", **format) ? arg->min_field =
		parse_nbr(format) : 0;
		**format == '.' ? arg->precision = parse_nbr(format) : 0;
		if (ft_strchr("lhL", **format))
		{
			arg->type[1] = **format;
			arg->type[1] == *(*format - 1) ? arg->type[0] = **format : 0;
		}
		**format ? (*format)++ : 0;
	}
	if (ft_strchr("cspdiouxX%fB", **format) && **format)
	{
		arg->type[2] = **format;
		(*format)++;
	}
	arg->prec_ori = arg->precision;
}

/*
** ft_parse_arg
** retrieve all the flags and the conversion from the format, puts it in a
** t_arg struct, and send it to the dispatching function to retrieve the arg
** and apply all the flags
** -
** takes a pointer to the string to fill, a string containing the format and
** an argument va_list
** return 1, and 0 if a malloc fails
*/

static int	parse_arg(t_printf *pr, char **format, va_list va)
{
	t_arg	arg;
	char	*arg_str;

	ft_bzero(&arg, sizeof(t_arg));
	arg.precision = -1;
	parse_flags(format, &arg, va);
	if (!(arg_str = base_str(&arg, va, pr)))
		return (0);
	if (!(flags_str(&arg, &arg_str)))
		return (0);
	if (!(pr->str = ft_strjoin_free(pr->str, arg_str)))
		return (0);
	return (1);
}

/*
** ft_vasprintf
** allocate a string of the right size to put a formatted output inside, then
** do it
** -
** takes a pointer to the string to fill, a string containing the format and
** an argument va_list
** return the length of the string putted in str, and -1 if a malloc fails
*/

t_printf	*pr_vasprintf(char *format, va_list va)
{
	int			i;
	t_printf	*pr;

	if (!(pr = pr_alloc()) || !*format)
		return (pr ? pr : 0);
	i = 0;
	pr->str = ft_strnew(0);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (!(pr->str = ft_strjoin_free(pr->str, ft_strndup(format, i))))
				return (0);
			format += i + 1;
			i = 0;
			if (!(parse_arg(pr, &format, va)))
				return (0);
			i--;
		}
		i++;
	}
	if (!(pr->str = ft_strjoin_free(pr->str, ft_strdup(format))))
		return (0);
	return (pr);
}

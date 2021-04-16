/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/12 19:27:01 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define DEFAULT_PREC 6
# define MAX_EXPECTED_DIGITS 4951
# define MAX_EXPECTED_A6M 1000

# include <stdarg.h>

typedef struct	s_arg{
	char	type[3];
	int		hash;
	int		minus;
	int		plus;
	int		space;
	int		zero;
	int		min_field;
	int		precision;
	int		pointer;
	int		is_zero;
	int		prec_ori;
}				t_arg;

/*
** the retardest
*/

typedef struct	s_printf
{
	char	*str;
	int		nzero;
	int		*zero;
}				t_printf;

char			*base_str(t_arg *arg, va_list va, t_printf *pr);
char			*ldtos_prec(t_arg *arg, long double nb);
int				flags_str(t_arg *arg, char **arg_str);
int				oxx_str(t_arg *arg, char **arg_str);
t_printf		*pr_vasprintf(char *format, va_list va);

t_printf		*pr_alloc(void);
char			c_base(t_arg *arg, va_list va, t_printf *pr);

#endif

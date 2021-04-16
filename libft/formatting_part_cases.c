/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatting_part_cases.c                            :+:      :+:    :+:   */
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
** c_base
** base string portion for chars, because this 0 case is death itself
*/

char		c_base(t_arg *arg, va_list va, t_printf *pr)
{
	char	c;
	int		deja_vu;

	c = va_arg(va, int);
	if (!c)
	{
		deja_vu = arg->minus ? 0 : 1;
		if (deja_vu)
			deja_vu = arg->min_field ? arg->min_field - 1 : 0;
		if (pr->nzero < MAX_EXPECTED_A6M)
			pr->zero[pr->nzero++] = ft_strlen(pr->str) + deja_vu;
		c = '0';
	}
	return (c);
}

/*
** pr_alloc
** allocates pr and the zero tab
*/

t_printf	*pr_alloc(void)
{
	t_printf *pr;

	if (!(pr = (t_printf *)ft_memalloc(sizeof(t_printf))))
		return (0);
	pr->zero = (int *)ft_memalloc(MAX_EXPECTED_A6M);
	return (pr);
}

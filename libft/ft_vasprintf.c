/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:27:37 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

/*
** ft_vasprintf
** allocate a string of the right size to put a formatted output inside, then
** do it
** -
** takes a pointer to the string to fill, a string containing the format and
** an argument va_list
** return the length of the string putted in str, and -1 if a malloc fails
*/

int	ft_vasprintf(char **restrict str, char *format, va_list va)
{
	t_printf	*pr;
	int			ret;

	if (!(pr = pr_vasprintf(format, va)))
		return (-1);
	*str = pr->str ? pr->str : ft_strnew(0);
	ret = ft_strlen(*str);
	while (pr->nzero--)
		(*str)[pr->zero[pr->nzero]] = 0;
	pr->zero ? free(pr->zero) : 0;
	free(pr);
	return (ret);
}

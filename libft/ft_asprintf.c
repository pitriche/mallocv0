/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:27:37 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_asprintf
** use ft_vasprintf on its parameters
** -
** takes a pointer to the string to fill, a string containing the format and
** an undetermined number of arguments
** return the length of the string putted in str, and -1 if a malloc fails
*/

int	ft_asprintf(char **restrict str, const char *restrict format, ...)
{
	va_list va;
	int		ret;

	va_start(va, format);
	ret = ft_vasprintf(str, (char *)format, va);
	va_end(va);
	return (ret);
}

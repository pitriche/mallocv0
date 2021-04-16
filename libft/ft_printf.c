/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:27:37 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

/*
** ft_printf
** use ft_vasprintf on its parameters to create a string, write the string on
** the standard output, then free it
** -
** takes an int describing the fd to write on, a string containing the format
** and an undetermined number of arguments
** return the length of the string putted in str, and -1 if a malloc fails
*/

int	ft_printf(const char *restrict format, ...)
{
	va_list	va;
	char	*str;
	int		ret;

	va_start(va, format);
	if ((ret = ft_vasprintf(&str, (char *)format, va)) == -1)
		return (-1);
	va_end(va);
	write(1, str, ret);
	free(str);
	return (ret);
}

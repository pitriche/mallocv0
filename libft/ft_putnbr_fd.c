/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 14:40:28 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_putnbr_fd
** write a number on a given fd, but with style
** -
** takes an int to print and an int describing a fd
** return nothing
*/

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned n;

	nb < 0 ? ft_putchar_fd('-', fd) : 0;
	n = nb < 0 ? -nb : nb;
	n > 9 ? ft_putnbr_fd(n / 10, fd) : 0;
	ft_putchar_fd(n % 10 + '0', fd);
}

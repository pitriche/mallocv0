/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 14:40:28 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:37:16 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_putnbr
** print an int
** -
** takes an int
** return nothing
*/

void	ft_putnbr(int nb)
{
	unsigned n;

	nb < 0 ? ft_putchar('-') : 0;
	n = nb < 0 ? -nb : nb;
	n > 9 ? ft_putnbr(n / 10) : 0;
	ft_putchar(n % 10 + '0');
}

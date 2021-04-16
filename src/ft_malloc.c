/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre42 <pierre42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:24:44 by pitriche          #+#    #+#             */
/*   Updated: 2020/07/08 16:49:30 by pierre42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include "libft.h"

void	*ft_malloc(size_t size)
{
	t_malloc *d;

	d = malloc_data();
	if (size <= 0)
		return (0);
	else if (size <= TINY_SIZE)
		return (tiny_malloc(d, (unsigned)size));
	else if (size <= SMAL_SIZE)
		return (small_malloc(d, (unsigned)size));
	else
		return (large_malloc(d, size));	
}

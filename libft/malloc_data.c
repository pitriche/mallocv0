/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre42 <pierre42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 16:18:31 by pitriche          #+#    #+#             */
/*   Updated: 2020/07/08 15:52:57 by pierre42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void		*malloc_alloc(size_t size)
{
	void	*tmp;

	tmp = mmap(0, size, PROT_WRITE | PROT_READ | PROT_EXEC, MAP_SHARED |
		MAP_ANONYMOUS, -1, 0);
	return (tmp > 0 ? tmp : 0);
}

t_malloc	*malloc_data(void)
{
	static t_malloc m_data;

	if (!m_data.ps)
		m_data.ps = (size_t)getpagesize();
	return (&m_data);
}

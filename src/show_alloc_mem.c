/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre42 <pierre42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 18:19:22 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/16 17:18:21 by pierre42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include "libft.h"

static unsigned long	pr_tiny(t_malloc *d)
{
	t_ma_tiny		*tmpt;
	unsigned		i;
	unsigned long	total;

	tmpt = d->tiny;
	total = 0UL;
	ft_printf("TINY : 0x%X\n", tmpt);
	while (tmpt)
	{
		i = -1;
		while(++i < tmpt->n_elem)
		{
			ft_printf("0x%X - 0x%X : %lu octets\n", tmpt->mem +
				tmpt->meta[i].off, tmpt->mem + tmpt->meta[i].off +
				tmpt->meta[i].len, tmpt->meta[i].len);
			total += tmpt->meta[i].len;
		}
		tmpt = tmpt->next;
	}
	return (total);
}

static unsigned long	pr_small(t_malloc *d)
{
	t_ma_smal		*tmps;
	unsigned		i;
	unsigned long	total;

	tmps = d->smal;
	total = 0UL;
	ft_printf("SMALL : 0x%X\n", tmps);
	while (tmps)
	{
		i = -1;
		while(++i < tmps->n_elem)
		{
			ft_printf("0x%X - 0x%X : %lu octets\n", tmps->mem +
				tmps->meta[i].off, tmps->mem + tmps->meta[i].off +
				tmps->meta[i].len, tmps->meta[i].len);
			total += tmps->meta[i].len;
		}
		tmps = tmps->next;
	}
	return (total);
}

static unsigned long	pr_large(t_malloc *d)
{
	t_ma_larg	*tmpl;
	unsigned	i;
	unsigned long	total;

	tmpl = d->larg;
	total = 0UL;
	ft_printf("LARGE : 0x%X\n", tmpl);
	while (tmpl)
	{
		i = -1;
		while(++i < tmpl->n_elem)
		{
			ft_printf("0x%X - 0x%X : %lu octets\n", tmpl->mem[i], tmpl->mem[i]
				+ tmpl->len[i], tmpl->len[i]);
			total += tmpl->len[i];
		}
		tmpl = tmpl->next;
	}
	return (total);
}

void					show_alloc_mem(void)
{
	unsigned long	total;
	t_malloc		*d;

	d = malloc_data();
	total = 0UL;
	total += pr_tiny(d);
	total += pr_small(d);
	total += pr_large(d);
	ft_printf("Total : %llu octets\n", total);
}

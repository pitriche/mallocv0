/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre42 <pierre42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 18:19:22 by pitriche          #+#    #+#             */
/*   Updated: 2020/07/08 19:08:05 by pierre42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include "libft.h"

static void	pr_tiny(t_malloc *d)
{
	t_ma_tiny	*tmpt;
	unsigned	i;

	tmpt = d->tiny;
	ft_printf("TINY : 0x%X\n", tmpt);
	while (tmpt)
	{
		i = -1;
		while(++i < tmpt->n_elem)
			ft_printf("0x%X - 0x%X : %lu octets\n", tmpt->mem +
				tmpt->meta[i].off, tmpt->mem + tmpt->meta[i].off +
				tmpt->meta[i].len, tmpt->meta[i].len);
		tmpt = tmpt->next;
	}
}

static void	pr_small(t_malloc *d)
{
	t_ma_smal	*tmps;
	unsigned	i;

	tmps = d->smal;
	ft_printf("SMALL : 0x%X\n", tmps);
	while (tmps)
	{
		i = -1;
		while(++i < tmps->n_elem)
			ft_printf("0x%X - 0x%X : %lu octets\n", tmps->mem +
				tmps->meta[i].off, tmps->mem + tmps->meta[i].off +
				tmps->meta[i].len, tmps->meta[i].len);
		tmps = tmps->next;
	}
}

static void	pr_large(t_malloc *d)
{
	t_ma_larg	*tmpl;
	unsigned	i;

	tmpl = d->larg;
	ft_printf("LARGE : 0x%X\n", tmpl);
	while (tmpl)
	{
		i = -1;
		while(++i < tmpl->n_elem)
			ft_printf("0x%X - 0x%X : %lu octets\n", tmpl->mem[i], tmpl->mem[i]
				+ tmpl->len[i], tmpl->len[i]);
		tmpl = tmpl->next;
	}
}

void		show_alloc_mem(void)
{
	t_malloc	*d;

	d = malloc_data();
	pr_tiny(d);
	pr_small(d);
	pr_large(d);
}

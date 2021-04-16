/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre42 <pierre42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:24:44 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/16 17:19:57 by pierre42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include "libft.h"

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;

	void *p1 = ft_malloc(1 * 8000);
	void *p2 = ft_malloc(2 * 8000);
	void *p3 = ft_malloc(3 * 80);
	void *p4 = ft_malloc(4 * 80);
	void *p5 = ft_malloc(5 * 8);
	show_alloc_mem();
	ft_strcpy(p5, "lololol itz funi");
	ft_printf(">%s<\n", p5);
	ft_strcpy(p5, "lololol itz funi and it ovarflow lalalalalalallalalalla");

	show_alloc_mem();
	ft_free(p4);
	ft_free(p3);
	ft_free(p1);
	ft_free(p2);
	ft_printf(">%p<\n", p5);
	p5 = ft_realloc(p5, 1200);
	ft_printf(">%p<\n", p5);
	ft_free(p5);
	show_alloc_mem();
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_heap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:44:47 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/20 18:58:53 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/core.h"

void		print_heap(int *h, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		ft_putstr_fd("HEAP [", 1);
		ft_putnbr_fd(i, 1);
		ft_putstr_fd("] = [", 1);
		ft_putnbr_fd(h[i], 1);
		ft_putstr_fd("]\n", 1);
		++i;
	}
}

static void	display_nbr(UINT i, t_val *val)
{
	if (i < val->size_a)
		ft_putnbr_fd(val->a[i], 1);
	else
		ft_putstr_fd(".", 1);
	ft_putstr_fd("]\t|\t[", 1);
	ft_putnbr_fd(i, 1);
	ft_putstr_fd("] = [", 1);
	if (i < val->size_b)
		ft_putnbr_fd(val->b[i], 1);
	else
		ft_putstr_fd(".", 1);
}

void		print_heaps(t_val *val)
{
	size_t max_i;
	size_t i;

	if (!val->bonus_visualize)
		return ;
	max_i = val->size_a > val->size_b ? val->size_a : val->size_b;
	i = 0;
	ft_putstr_fd("\n\t---------------------------------\n", 1);
	ft_putstr_fd("\t[HEAP A]\t\t[HEAP B]\n\n", 1);
	while (i < max_i)
	{
		ft_putstr_fd("\t[", 1);
		ft_putnbr_fd(i, 1);
		ft_putstr_fd("] = [", 1);
		display_nbr(i, val);
		ft_putstr_fd("]\n", 1);
		++i;
	}
}

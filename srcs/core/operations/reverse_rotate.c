/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:42:11 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/24 12:09:46 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/core.h"

int	rra(t_val *val, t_bool print)
{
	int tmp;

	if (val->size_a <= 1)
		return (1);
	tmp = val->a[val->size_a - 1];
	--val->size_a;
	ft_move_tab_down(val->a, &val->size_a);
	val->a[0] = tmp;
	print_output(val, "rra", print);
	return (0);
}

int	rrb(t_val *val, t_bool print)
{
	int tmp;

	if (val->size_b <= 1)
		return (1);
	tmp = val->b[val->size_b - 1];
	--val->size_b;
	ft_move_tab_down(val->b, &val->size_b);
	val->b[0] = tmp;
	print_output(val, "rrb", print);
	return (0);
}

int	rrr(t_val *val, t_bool print)
{
	int tmp;

	if (val->size_a > 1)
	{
		tmp = val->a[val->size_a - 1];
		--val->size_a;
		ft_move_tab_down(val->a, &val->size_a);
		val->a[0] = tmp;
	}
	if (val->size_b > 1)
	{
		tmp = val->b[val->size_b - 1];
		--val->size_b;
		ft_move_tab_down(val->b, &val->size_b);
		val->b[0] = tmp;
	}
	print_output(val, "rrr", print);
	return (0);
}

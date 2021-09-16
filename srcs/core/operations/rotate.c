/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:21:11 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/24 12:10:18 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/core.h"

int	ra(t_val *val, t_bool print)
{
	int tmp;

	if (val->size_a <= 1)
		return (1);
	tmp = val->a[0];
	ft_move_tab_up(val->a, &val->size_a);
	val->a[val->size_a] = tmp;
	++val->size_a;
	print_output(val, "ra", print);
	return (0);
}

int	rb(t_val *val, t_bool print)
{
	int tmp;

	if (val->size_b <= 1)
		return (1);
	tmp = val->b[0];
	ft_move_tab_up(val->b, &val->size_b);
	val->b[val->size_b] = tmp;
	++val->size_b;
	print_output(val, "rb", print);
	return (0);
}

int	rr(t_val *val, t_bool print)
{
	int tmp;

	if (val->size_a > 1)
	{
		tmp = val->a[0];
		ft_move_tab_up(val->a, &val->size_a);
		val->a[val->size_a] = tmp;
		++val->size_a;
	}
	if (val->size_b > 1)
	{
		tmp = val->b[0];
		ft_move_tab_up(val->b, &val->size_b);
		val->b[val->size_b] = tmp;
		++val->size_b;
	}
	print_output(val, "rr", print);
	return (0);
}

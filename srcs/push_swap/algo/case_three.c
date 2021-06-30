/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:04:37 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/19 14:21:27 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

static int	compare_third_value(t_val *val)
{
	int i0;
	int i1;
	int i2;

	i0 = val->a[0];
	i1 = val->a[1];
	i2 = val->a[2];
	if (i0 < i1 && i1 < i2 && i2 > i0)
		return (0);
	if (i0 > i1 && i1 < i2 && i2 > i0)
		return (1);
	if (i0 > i1 && i1 > i2 && i2 < i0)
		return (2);
	if (i0 < i1 && i1 > i2 && i2 > i0)
		return (3);
	if (i0 < i1 && i1 > i2 && i2 < i0)
		return (4);
	if (i0 > i1 && i1 < i2 && i2 < i0)
		return (5);
	return (-1);
}

int			case_three(t_val *val)
{
	int i;

	if ((i = compare_third_value(val)) == -1)
		return (print_error("Error : Algorithm", 1));
	if (i == 0)
		return (0);
	if (i == 1)
		sa(val);
	if (i == 2)
	{
		sa(val);
		rra(val);
	}
	if (i == 3)
	{
		sa(val);
		ra(val);
	}
	if (i == 4)
		rra(val);
	if (i == 5)
		ra(val);
	return (0);
}

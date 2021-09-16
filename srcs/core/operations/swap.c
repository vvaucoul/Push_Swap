/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 22:12:18 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/24 12:08:56 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/core.h"

int	sa(t_val *val, t_bool print)
{
	int tmp;

	if (val->size_a < 2)
		return (1);
	tmp = val->a[1];
	val->a[1] = val->a[0];
	val->a[0] = tmp;
	print_output(val, "sa", print);
	return (0);
}

int	sb(t_val *val, t_bool print)
{
	int tmp;

	if (val->size_b < 2)
		return (1);
	tmp = val->b[1];
	val->b[1] = val->b[0];
	val->b[0] = tmp;
	print_output(val, "sb", print);
	return (0);
}

int	ss(t_val *val, t_bool print)
{
	int tmp;

	if (val->size_a > 1)
	{
		tmp = val->a[1];
		val->a[1] = val->a[0];
		val->a[0] = tmp;
	}
	if (val->size_b > 1)
	{
		tmp = val->b[1];
		val->b[1] = val->b[0];
		val->b[0] = tmp;
	}
	print_output(val, "ss", print);
	return (0);
}

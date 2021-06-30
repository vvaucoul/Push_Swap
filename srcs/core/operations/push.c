/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:20:54 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/19 15:18:36 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/core.h"

int	pa(t_val *val)
{
	if (val->size_b == 0)
		return (1);
	if (!(val->a = ft_realloc_int(val->a, val->size_a + 1)))
		return (-1);
	ft_move_tab_down(val->a, &val->size_a);
	val->a[0] = val->b[0];
	ft_move_tab_up(val->b, &val->size_b);
	print_output(val, "pa");
	return (0);
}

int	pb(t_val *val)
{
	if (val->size_a == 0)
		return (1);
	if (!(val->b = ft_realloc_int(val->b, val->size_b + 1)))
		return (-1);
	ft_move_tab_down(val->b, &val->size_b);
	val->b[0] = val->a[0];
	ft_move_tab_up(val->a, &val->size_a);
	print_output(val, "pb");
	return (0);
}

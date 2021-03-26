/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hunter_sort_three.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:16:14 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/26 14:03:05 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/push_swap.h"

int				hunter_sort_three_just_a(t_val *val)
{
	int a;
	int b;
	int c;

	a = val->a[0];
	b = val->a[1];
	c = val->a[2];
	if (a < c && c < b)
	{
		sa(val, TRUE);
		ra(val, TRUE);
	}
	else if (b < a && a < c)
		sa(val, TRUE);
	else if (c < a && a < b)
		rra(val, TRUE);
	else if (b < c && c < a)
		ra(val, TRUE);
	if (c < b && b < a)
	{
		ra(val, TRUE);
		sa(val, TRUE);
	}
	return (0);
}

int				hunter_sort_three_a(t_val *val)
{
	int a;
	int b;
	int c;

	a = val->a[0];
	b = val->a[1];
	c = val->a[2];
	if (val->size_a == 3)
		return (hunter_sort_three_just_a(val));
	if (a > b)
		val->b[0] < val->b[1] ? ss(val, TRUE) : sa(val, TRUE);
	if (c > a && a > b)
		return (1);
	ra(val, TRUE);
	if (val->b[0] < val->b[1])
		ss(val, TRUE);
	else
		sa(val, TRUE);
	rra(val, TRUE);
	if (b > c && a > c)
		sa(val, TRUE);
	return (0);
}

static int		hunter_sort_three_b_02(t_val *val, int b, int c)
{
	sb(val, TRUE);
	pa(val, TRUE);
	if (b < c)
		sa(val, TRUE);
	pa(val, TRUE);
	return (0);
}

int				hunter_sort_three_b(t_val *val)
{
	int a;
	int b;
	int c;

	if (val->size_b != 3)
		return (1);
	a = val->b[0];
	b = val->b[1];
	c = val->b[2];
	if (a > b)
		pa(val, TRUE);
	sb(val, TRUE);
	pa(val, TRUE);
	if (b < c && c < a)
		return (pa(val, TRUE));
	else if ((c < a && a < b) || (b < a && a < c))
	{
		(b > c) ? pa(val, TRUE) : sa(val, TRUE);
		return (pa(val, TRUE));
	}
	hunter_sort_three_b_02(val, b, c);
	return (0);
}

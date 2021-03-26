/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hunter_sort_three.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:16:14 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/26 13:16:38 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/push_swap.h"

int hunter_sort_three_just_a(t_val *val)
{
	int a = val->a[0];
	int b = val->a[1];
	int c = val->a[2];

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

int hunter_sort_three_a(t_val *val)
{
	int a = val->a[0];
	int b = val->a[1];
	int c = val->a[2];


	if (val->size_a == 3)
		return (hunter_sort_three_just_a(val));

	if (a > b)
	{
		if (val->b[0] < val->b[1])
			ss(val, TRUE);
		else
			sa(val, TRUE);
	}
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

int hunter_sort_three_b(t_val *val)
{

	if (val->size_b != 3)
		return (1);

	int a = val->b[0];
	int b = val->b[1];
	int c = val->b[2];


	if (a > b)
		pa(val, TRUE);
	sb(val, TRUE);
	pa(val, TRUE);
	if (b < c && c < a)
		return (pa(val, TRUE));
	else if ((c < a && a < b) || (b < a && a < c))
	{
		if (b > c)
			pa(val, TRUE);
		else
			sa(val, TRUE);
		return (pa(val, TRUE));
	}
	sb(val, TRUE);
	pa(val, TRUE);
	if (b < c)
		sa(val, TRUE);
	pa(val, TRUE);
	return (0);
}

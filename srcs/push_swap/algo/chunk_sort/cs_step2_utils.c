/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cs_step2_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:07:19 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/20 18:54:21 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/push_swap.h"

/*
** Utils
*/

/*
** Rotation RETURN
** [1] rra/b [0] ra/b
*/

int	select_rotation(int *h, int value, UINT size)
{
	UINT i;

	i = 0;
	while (h[i] != value)
		++i;
	if (i > size / 2)
		return (1);
	else
		return (0);
	return (0);
}

/*
** start with max
**
** Nearest RETURN
** [1] max [0] min
*/

int	min_or_max_is_nearest(int *h, UINT size)
{
	int tmp;
	int pos_max;
	int pos_min;
	int i;

	pos_max = 0;
	pos_min = 0;
	i = 0;
	tmp = get_max_value(h, size);
	while (h[i] != tmp)
	{
		++pos_max;
		++i;
	}
	i = 0;
	tmp = get_min_value(h, size);
	while (h[i] != tmp)
	{
		++pos_min;
		++i;
	}
	return (pos_max > pos_min);
}

/*
** MIN / MAX Functions
*/

int	get_max_value(int *h, UINT size)
{
	int		max;
	UINT	i;

	i = 0;
	max = h[0];
	while (i < size)
	{
		if (h[i] > max)
			max = h[i];
		++i;
	}
	return (max);
}

int	get_min_value(int *h, UINT size)
{
	int		min;
	UINT	i;

	i = 0;
	min = h[0];
	while (i < size)
	{
		if (h[i] < min)
			min = h[i];
		++i;
	}
	return (min);
}

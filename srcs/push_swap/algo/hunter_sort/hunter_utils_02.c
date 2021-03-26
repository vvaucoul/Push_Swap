/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hunter_utils_02.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:19:14 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/26 13:19:27 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/push_swap.h"

int	hunter_median_under(int *heap, UINT size, int median)
{
	UINT i = 0;

	while (i < size)
	{
		if (heap[i] < median)
			return (1);
		++i;
	}
	return (0);
}

int	hunter_median_upper(int *heap, UINT size, int median)
{
	UINT i = 0;

	while (i < size)
	{
		if (heap[i] >= median)
			return (1);
		++i;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hunter_utils_02.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:19:14 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/26 14:12:18 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/push_swap.h"

int		hunter_median_under(int *heap, UINT size, int median)
{
	UINT i;

	i = 0;
	while (i < size)
	{
		if (heap[i] < median)
			return (1);
		++i;
	}
	return (0);
}

int		hunter_median_upper(int *heap, UINT size, int median)
{
	UINT i;

	i = 0;
	while (i < size)
	{
		if (heap[i] >= median)
			return (1);
		++i;
	}
	return (0);
}

int		hunter_median(int *heap, UINT size, UINT div)
{
	int		*tab;
	int		middle;

	tab = ft_select_sort(heap, size);
	middle = tab[size / div];
	free(tab);
	return (middle);
}

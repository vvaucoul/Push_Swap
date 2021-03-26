/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hunter_utils_02.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:19:14 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/26 13:57:18 by vvaucoul         ###   ########.fr       */
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
	int *tab;
	int middle;
	int i;

	i = 0;
	if (!(tab = malloc(sizeof(int) * size + 1)))
		return (-1);
	while (i < size)
	{
		tab[i] = heap[i];
		++i;
	}
	tab[i] = 0;
	tab = ft_select_sort(tab, size);
	middle = tab[size / div];
	free(tab);
	return (middle);
}

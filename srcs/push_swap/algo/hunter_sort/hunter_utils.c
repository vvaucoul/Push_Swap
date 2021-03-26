/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hunter_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:18:58 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/26 13:56:53 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/push_swap.h"

/*
** Utils
*/

int		heap_is_sorted(int *heap, UINT size)
{
	UINT i;

	i = 0;
	while (i < size - 1)
	{
		if (heap[i + 1] < heap[i])
			return (0);
		++i;
	}
	return (1);
}

int		check_heap_reverse_sort(int *heap, UINT size)
{
	UINT i;

	i = 0;
	while (i < size - 1)
	{
		if (heap[i + 1] > heap[i])
			return (0);
		++i;
	}
	return (1);
}

int		heap_is_reverse_sorted(int *heap, UINT size)
{
	UINT i;

	i = 0;
	while (i < size - 1)
	{
		if (heap[i + 1] > heap[i])
			return (0);
		++i;
	}
	return (1);
}

int		check_heap_is_sorted(int *heap, UINT size)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		if (heap[i + 1] < heap[i])
			return (0);
		++i;
	}
	return (1);
}

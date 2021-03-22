/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:31:06 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/19 15:28:42 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/push_swap.h"

int	is_max_value(int *tab, int size)
{
	int i;
	int max;

	i = 0;
	max = tab[0];
	while (i < size)
	{
		if (tab[i] > max)
			max = tab[i];
		++i;
	}
	return (max);
}

int	is_min_value(int *tab, int size)
{
	int i;
	int min;

	i = 0;
	min = tab[0];
	while (i < size)
	{
		if (tab[i] < min)
			min = tab[i];
		++i;
	}
	return (min);
}

int	min_r(int *tab, int size, int value)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (tab[i] == value)
			return (i);
		++i;
	}
	return (0);
}

int	min_rr(int *tab, int size, int value)
{
	int i;

	i = size;
	while (i >= 0)
	{
		if (tab[i] == value)
			return (size - i - 1);
		--i;
	}
	return (0);
}

int	is_next_min_value(int *tab, int size)
{
	int i;
	int j;
	int *new_tab;
	int tmp;
	int next_min;

	i = -1;
	j = 0;
	if (size <= 1)
		return (tab[0]);
	tmp = is_min_value(tab, size);
	if (!(new_tab = malloc(sizeof(int) * (size + 1))))
		return (-1);
	while (++i < size)
	{
		if (tab[i] != tmp)
		{
			new_tab[j] = tab[i];
			++j;
		}
	}
	new_tab[size] = 0;
	next_min = is_min_value(new_tab, size - 1);
	free(new_tab);
	return (next_min);
}

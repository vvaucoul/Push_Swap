/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:09:03 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/20 19:40:43 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/core.h"

static int		*assign_tab(int *tab, size_t size)
{
	int		*new_tab;
	size_t	i;

	i = 0;
	if (!(new_tab = malloc(sizeof(int) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		new_tab[i] = tab[i];
		++i;
	}
	new_tab[i] = 0;
	return (new_tab);
}

static int		get_min_value_index(int *nbr, int start)
{
	int min;
	int si;
	int i;

	i = start;
	si = 0;
	min = 256;
	while (nbr[i])
	{
		if (nbr[i] < min)
		{
			min = nbr[i];
			si = i;
		}
		++i;
	}
	return (si);
}

int				*ft_select_sort(int *default_nbr, size_t size)
{
	int *nbr;
	int i;
	int min_value_index;
	int len;
	int tmp;

	nbr = assign_tab(default_nbr, size);
	i = 0;
	len = size;
	while (i < len)
	{
		min_value_index = get_min_value_index(nbr, i);
		tmp = nbr[i];
		nbr[i] = nbr[min_value_index];
		nbr[min_value_index] = tmp;
		++i;
	}
	return (nbr);
}

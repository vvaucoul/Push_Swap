/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hunter_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:49:06 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/22 15:15:20 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/push_swap.h"

/*
** DEBUG
*/

# include <stdio.h>


static void print_hunter(t_hunter *hunter, int print_a)
{
	int i;
	int mi;

	i = 0;
	mi = print_a ? hunter->size_a : hunter->size_b;
	while (i < mi)
	{
		printf("- [%d] : [%d] | POIDS [%ld]\n", i, print_a ? hunter->a[i].nbr : hunter->b[i].nbr, print_a ? hunter->a[i].poids : hunter->b[i].poids);
		++i;
	}
	printf("Hunter %s = [%ld]\n", print_a ? "HEAP A" : "HEAP B", print_a ? hunter->size_a : hunter->size_b);
}

static t_poids	get_nbr_poids(int *h, UINT size, int index, int value)
{
	t_poids	poids;
	int		*sorted_tab;
	int		i;

	i = 0;
	sorted_tab = ft_select_sort(h, size);
	while (i < index)
	{
		ft_move_tab_up(sorted_tab, &size);
		++i;
	}
	free(sorted_tab);
	poids.nbr = value;
	poids.poids = i;
	return (poids);
}

static int	init_hunter_sort(t_val *val, t_hunter *hunter)
{
	UINT	i;

	if (!(hunter->a = malloc(sizeof(t_poids) * (val->size_a + 1))))
		return (-1);
	if (!(hunter->b = malloc(sizeof(t_poids) * (val->size_b + 1))))
		return (-1);
	i = 0;
	while (i < val->size_a)
	{
		hunter->a[i] = get_nbr_poids(val->a, val->size_a, i, val->a[i]);
		++i;
	}
	hunter->size_a = val->size_a;
	i = 0;
	while (i < val->size_b)
	{
		hunter->b[i] = get_nbr_poids(val->b, val->size_b, i, val->b[i]);
		++i;
	}
	hunter->size_b = val->size_b;
	return (0);
}

static int free_hunter(t_hunter *hunter)
{
	free(hunter->a);
	free(hunter->b);
	return (0);
}

int	hunter_algo(t_val *val)
{
	t_hunter hunter;

	init_hunter_sort(val, &hunter);
	print_hunter(&hunter, TRUE);
	print_hunter(&hunter, FALSE);
	return (free_hunter(&hunter));
}

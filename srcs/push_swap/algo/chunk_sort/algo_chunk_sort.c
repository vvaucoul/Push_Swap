/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_chunk_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:55:53 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/24 11:25:07 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/push_swap.h"

/*
** 1 - recuperer median/moyenne
** 2 - mettre tous les nombres < a la median/moyenne sur B
**
** 3 - recuperer median/moyenne dans b
** 4 - placer les nombres > a la median/moyenne au dessus de A sinon,
** en dessous de A
**
** 5 - rotate jusqu a que a soit trié et mettre le reste des nombres dans B
** 6 - placer du plus grand au plus petit de la pile B a la pile A puis rotate
** jusqu a que A soit trie
*/

/*
** placer tous les nombres < median sur b
*/

static int	step_01(t_val *val, int median)
{
	int max_size;
	int i;

	max_size = val->size_a;
	i = 0;
	while (i < max_size)
	{
		if (!(has_number_inferior_median(val->a, median, val->size_a)))
			break ;
		if (val->a[0] < median)
			pb(val, TRUE);
		else
			ra(val, TRUE);
		++i;
	}
	return (0);
}

/*
** placer median inf dans A
**
** l_median = Local Median;
** nb_top_nbr = obtenir le nombre de nombre place en haut afin de rotate \
** puis de placer le reste dans b
*/

int			step_02(t_val *val)
{
	int max_size;
	int i;
	int nb_top_nbr;
	int default_size;

	default_size = val->size_a;
	max_size = val->size_b;
	i = 0;
	nb_top_nbr = 0;
	while (i < max_size)
	{
		step_02_loop(val, &nb_top_nbr);
		++i;
	}
	if (!heap_solved(val))
		return (0);
	step_02_rotate_heap(val, nb_top_nbr, default_size);
	return (0);
}

int			algo_03(t_val *val)
{
	int		m;
	int		*tab;

	while (heap_solved(val))
	{
		tab = ft_select_sort(val->a, val->size_a);
		m = get_heap_median(tab, val->size_a);
		free(tab);
		step_01(val, m);
		step_02(val);
	}
	return (0);
}

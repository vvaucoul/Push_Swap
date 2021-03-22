/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hunter_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:49:06 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/22 21:02:53 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/push_swap.h"


/*
** Hunter Sort
**
** [1] Push les 3 premiers nombres vers B
** [2] Case 3 heap B
** [3] tant que size a > 3
** [4] Case 3 Heap A
*/

/*
** DEBUG
*/

# include <stdio.h>


static int hunter_sort_hb(t_val *val, int size);

/*
** UTILS
*/

static int get_middle_stack(int *h, UINT size, int div)
{
	int *tab;
	int middle;

	tab = ft_select_sort(h, size);
	middle = tab[size / div];
	free(tab);
	printf("middle = [%d]\n", middle);
	return (middle);
}

// int	check_mid_low(t_list *stack, int mid)
static int heap_is_under_median(int *h, int size, int middle)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (h[i] < middle)
			return (1);
		++i;
	}
	return (0);
}

// int	check_mid_up(t_list *stack, int mid)
static int heap_is_upper_median(int *h, int size, int middle)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (h[i] >= middle)
			return (1);
		++i;
	}
	return (0);
}

//int	check_rev_sort(t_list *stack, int size)
static int reverse_sort(int *h, UINT size)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		if (h[i + 1] > h[i])
			return (0);
		++i;
	}
	return (1);
}

// int	stack_is_rev_sorted(t_list *stack_a)
static int heap_is_reverse_sorted(int *h, UINT size)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		if (h[i + 1] > h[i])
			return (0);
		++i;
	}
	return (1);
}

/*
** SORT FUNCTIONS
*/

static int hunter_sort_ha_helper(t_val *val, int size, t_hunter *hunter)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (val->a[0] < hunter->mid)
		{
			pb(val);
			++hunter->count_b;
		}
		else if (val->a[0] >= hunter->mid &&
		heap_is_under_median(val->a, size, hunter->mid))
		{
			if (val->size_b > 0 && hunter->flag && val->b[0] < hunter->mid_b)
			{
				rr(val);
			}
			else
				ra(val);
			++hunter->count_a;
		}
		++i;
	}
	return (0);
}

static int hunter_sort_ha(t_val *val, int size)
{
	t_hunter hunter;
	int count;

	hunter.mid = get_middle_stack(val->a, size, 2);
	hunter.mid_b = get_middle_stack(val->a, size, 4);
	hunter.flag = val->size_b ? 0 : 1;
	hunter.count_a = 0;
	hunter.count_b = 0;
	hunter_sort_ha_helper(val, size, &hunter);
	while (hunter.count_a > 0 && heap_solved(val) &&
	val->size_a != size - hunter.count_b)
	{
		rra(val);
		--hunter.count_a;
	}
	count = size - hunter.count_b;
	return (count);
}


static int hunter_sort_hb_helper(t_val *val, int size, t_hunter *hunter)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (val->b[0] >= hunter->mid)
		{
			pa(val);
			++hunter->count_a;
		}
		else if (val->b[0] < hunter->mid &&
		heap_is_upper_median(val->b, size, hunter->mid))
		{
			rb(val);
			++hunter->count_b;
		}
		++i;
	}

	i = 0;
	while (i < hunter->count_b && val->size_b != size - hunter->count_a &&
	!heap_is_reverse_sorted(val->b, size))
	{
		rrb(val);
		++i;
	}
	hunter_algo(val, hunter->count_a);
	hunter_sort_hb(val, size - hunter->count_a);
	return (0);
}

static int hunter_sort_hb(t_val *val, int size)
{
	t_hunter hunter;
	int		i;

	i = 0;
	if ((size >= 1 && size <= 2) || reverse_sort(val->b, size))
	{
		while (i < size)
		{
			pa(val);
			++i;
		}
		hunter_algo(val, size);
		return (0);
	}

	if (size == 3)
		return (case_three_b(val));

	hunter.mid = get_middle_stack(val->b, size, 2);
	hunter.count_a = 0;
	hunter.count_b = 0;
	hunter_sort_hb_helper(val, size, &hunter);
	return (0);
}

/*
** HunterFunction Called
*/

int	hunter_algo(t_val *val, int size)
{
	t_hunter hunter;

	hunter.count_a = hunter_sort_ha(val, size);
	hunter_algo(val, hunter.count_a);
	hunter.count_b = size - hunter.count_a;
	hunter_sort_hb(val, hunter.count_b);
	return (0);
}

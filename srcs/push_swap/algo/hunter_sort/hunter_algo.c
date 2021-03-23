/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hunter_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:49:06 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/23 16:32:09 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/push_swap.h"

/*
** DEBUG
*/

# include <stdio.h>


static int hunter_sort_hb(t_val *val, int size);

/*
** UTILS
*/

static int heap_is_sorted(int *h, UINT size)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		if (h[i + 1] < h[i])
			return (0);
		++i;
	}
	return (1);
}

static void	sort(int *array, int size)
{
	int i;
	int j;
	int tmp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (array[j] < array[j - 1])
			{
				tmp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = tmp;
			}
			++j;
		}
		++i;
	}
}

static int get_middle_stack(int *h, UINT size, int div)
{
	int *tab;
	int middle;
	int i;

	i = 0;
	if (!(tab = malloc(sizeof(int) * size + 1)))
		return (-1);
	while (i < size)
	{
		tab[i] = h[i];
		++i;
	}
	tab[i] = 0;
	sort(tab, size);
	middle = tab[size / div];
	free(tab);
	//printf("# Middle Stack [%d]\n", middle);
	return (middle);
}

// int	check_mid_low(t_list *stack, int mid)
static int heap_is_under_median(int *h, int size, int middle)
{
	int i;

	i = 0;
	//printf("# Heap Is - UNDER - Median | Size %d | Middle %d\n", size, middle);
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
	//printf("# Heap Is - UPPER - Median | Size %d | Middle %d\n", size, middle);
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

static int hunter_sort_three_b(t_val *val, UINT size)
{
	int a;
	int b;
	int c;

	//printf("# Sort Case Simple three B\n");
	a = val->b[0];
	b = val->b[1];
	c = val->b[2];

	if (a > b)
		pa(val);
	sb(val);
	pa(val);

	if (b < c && c < a)
		return (pa(val));
	else if ((c < a && a < b) || (b < a && a < c))
	{
		(b > c) ? pa(val) : sa(val);
		return (pa(val));
	}
	sb(val);
	pa(val);
	if (b < c)
		sa(val);
	pa(val);
	return (0);
}

static int hunter_simple_sort_three_a(t_val *val, UINT size)
{
	int a;
	int b;
	int c;

	//printf("# Sort Case Simple three A\n");
	a = val->a[0];
	b = val->a[1];
	c = val->a[2];
	if (a < c && c < b)
	{
		sa(val);
		ra(val);
	}
	else if (b < a && a < c)
		sa(val);
	else if (c < a && a < b)
		rra(val);
	else if (b < c && c < a)
		ra(val);
	if (c < b && b < a)
	{
		ra(val);
		sa(val);
	}
	return (0);
}

static int hunter_sort_three_a(t_val *val, UINT size)
{
	int a;
	int b;
	int c;

	//printf("# Sort Case three A\n");
	//printf("# Size = %ld\n", size);
	if (size == 3)
		return (hunter_simple_sort_three_a(val, size));
	a = val->a[0];
	//printf("\t# A = %d\n", a);
	b = val->a[1];
	//printf("\t# B = %d\n", b);
	c = val->a[2];
	//printf("\t# C = %d\n", c);

	//printf("\t# B[0] = %d\n", val->b[0]);
	//printf("\t# B[1] = %d\n", val->b[1]);
	if (a > b)
	{
		if (val->b[0] < val->b[1])
			ss(val);
		else
			sa(val);
	}
	if (c > a && a > b)
		return (0);
	ra(val);
	val->b[0] < val->b[1] ? ss(val) : sa(val);
	rra(val);
	if (b > c && a > c)
		sa(val);
	return (0);
}

static int hunter_sort_ha_helper(t_val *val, int size, t_hunter *hunter)
{
	int i;

	i = 0;
	//printf("### HUNTER SORT HA_HELPER ###\n\n");
	//printf("# Size = %d\n", size);
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
			//exit(0);
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
	//printf("### HUNTER SORT HA ###\n\n");
	//printf("# Size = %d\n", size);
	//printf("# FLag = %d\n", hunter.flag);
	hunter.count_a = 0;
	hunter.count_b = 0;
	hunter_sort_ha_helper(val, size, &hunter);
	//printf("# Count_A = %d\n", hunter.count_a);
	//printf("# Count_B = %d\n", hunter.count_b);
	while (hunter.count_a > 0 && heap_solved(val) &&
	val->size_a != size - hunter.count_b)
	{
		rra(val);
		--hunter.count_a;
	}
	count = size - hunter.count_b;
	//printf("# Return count = %d\n", count);
	return (count);
}


static int hunter_sort_hb_helper(t_val *val, int size, t_hunter *hunter)
{
	int i;

	i = 0;
	//printf("### HUNTER SORT HB_HELPER ###\n\n");
	//printf("# Size = %d\n", size);
	while (i < size)
	{
		if (val->b[0] >= hunter->mid)
		{
			pa(val);
			++hunter->count_a;
		}
		else if (val->size_b > 0 && val->b[0] < hunter->mid &&
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
	//exit(0);
	hunter_algo(val, hunter->count_a);
	hunter_sort_hb(val, size - hunter->count_a);
	return (0);
}

static int hunter_sort_hb(t_val *val, int size)
{
	t_hunter hunter;
	int		i;

	i = 0;
	//printf("### HUNTER SORT HB ###\n\n");
	//printf("# Size = %d\n", size);
	if ((size >= 1 && size <= 2) || reverse_sort(val->b, size))
	{
		while (i < size)
		{
			++i;
			pa(val);
		}
		hunter_algo(val, size);
		return (0);
	}
	if (size == 3)
		return (hunter_sort_three_b(val, size));
	hunter.mid = get_middle_stack(val->b, size, 2);
	hunter.count_a = 0;
	hunter.count_b = 0;
	//printf("# Count_A = %d\n", hunter.count_a);
	//printf("# Count_B = %d\n", hunter.count_b);
	hunter_sort_hb_helper(val, size, &hunter);
	//printf("# Count_A = %d\n", hunter.count_a);
	//printf("# Count_B = %d\n", hunter.count_b);
	return (0);
}

/*
** HunterFunction Called
*/

int	hunter_algo(t_val *val, int size)
{
	t_hunter hunter;

	//printf("### HUNTER ALGO ###\n\n");
	//printf("# Size = %d\n", size);
	if (!heap_solved(val))
	{
		//printf("### Heap is Solved\n");
		return (0);
	}
	if (size == 1 || heap_is_sorted(val->a, val->size_a))
	{
		//printf("### Heap is Sorted\n");
		return (0);
	}
	if (size == 2)
	{
		if (val->size_b > 0 && val->b[0] < val->b[1])
			return (ss(val));
		return (sa(val));
	}
	if (size == 3)
	{
		hunter_sort_three_a(val, val->size_a);
		//exit(0);
		return (0);
	}
	hunter.count_a = hunter_sort_ha(val, size);
	//printf("# Count_A = %d\n", hunter.count_a);
	hunter_algo(val, hunter.count_a);
	hunter.count_b = size - hunter.count_a;
	//printf("# Count_B = %d\n", hunter.count_b);
	hunter_sort_hb(val, hunter.count_b);
	return (0);
}

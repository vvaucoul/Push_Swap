/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_divide.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksarnyts <ksarnyts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:19:34 by ksarnyts          #+#    #+#             */
/*   Updated: 2021/03/23 16:31:22 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_three_b(t_list **stack_a, t_list **stack_b)
{
	int a;
	int b;
	int c;

	//printf("# Sort Case Simple three B\n");
	a = *(int *)((*stack_b)->content);
	b = *(int *)((*stack_b)->next->content);
	c = *(int *)((*stack_b)->next->next->content);
	if (a > b)
		command(stack_a, stack_b, "pa", 1);
	command(stack_a, stack_b, "sb", 1);
	command(stack_a, stack_b, "pa", 1);
	if (b < c && c < a)
		return (command(stack_a, stack_b, "pa", 1));
	else if ((c < a && a < b) || (b < a && a < c))
	{
		(b > c) ? command(stack_a, stack_b, "pa", 1) :\
			command(stack_a, stack_b, "sa", 1);
		return (command(stack_a, stack_b, "pa", 1));
	}
	command(stack_a, stack_b, "sb", 1);
	command(stack_a, stack_b, "pa", 1);
	if (b < c)
		command(stack_a, stack_b, "sa", 1);
	command(stack_a, stack_b, "pa", 1);
}

static void	div_a_help(t_list **s_a, t_list **s_b, int size, t_div *a)
{
	int i;

	i = 0;
	//printf("### HUNTER SORT HA_HELPER ###\n\n");
	//printf("# Size = %d\n", size);
	while (i++ < size)
	{
		if (*((int *)(*s_a)->content) < a->mid)
		{
			command(s_a, s_b, "pb", 1);
			a->count_b++;
		}
		else if (*((int *)(*s_a)->content) >= a->mid\
				&& check_mid_low(*s_a, a->mid))
		{
			//exit(0);
			if (*s_b && (*s_b)->next && a->flag\
					&& *((int *)(*s_b)->content) < a->mid_b)
				command(s_a, s_b, "rr", 1);
			else
				command(s_a, s_b, "ra", 1);
			a->count_a++;
		}
	}
}

int			divide_a(t_list **stack_a, t_list **stack_b, int size)
{
	t_div	*a;
	int		count;

	a = malloc(sizeof(t_div));
	a->mid = middle(*stack_a, size, 0, 2);
	a->mid_b = middle(*stack_a, size, 0, 4);
	(*stack_b) ? (a->flag = 0) :\
							(a->flag = 1);
	//printf("### HUNTER SORT HA ###\n\n");
	//printf("# Size = %d\n", size);
	//printf("# FLag = %d\n", a->flag);
	a->count_b = 0;
	a->count_a = 0;
	div_a_help(stack_a, stack_b, size, a);
	//printf("# Count_A = %d\n", a->count_a);
	//printf("# Count_B = %d\n", a->count_b);
	while (a->count_a-- > 0 && !stack_is_sorted(*stack_a)\
			&& ft_lstsize(*stack_a) != size - a->count_b)
		command(stack_a, stack_b, "rra", 1);
	count = size - a->count_b;
	free(a);
	//printf("# Return count = %d\n", count);
	return (count);
}

static void	div_b_help(t_list **s_a, t_list **s_b, int size, t_div *a)
{
	int i;

	i = 0;
	//printf("### HUNTER SORT HB_HELPER ###\n\n");
	//printf("# Size = %d\n", size);
	while (i++ < size)
	{
		if (*((int *)(*s_b)->content) >= a->mid)
		{
			command(s_a, s_b, "pa", 1);
			a->count_a++;
		}
		else if (*((int *)(*s_b)->content) < a->mid\
			&& check_mid_up(*s_b, a->mid))
		{
			command(s_a, s_b, "rb", 1);
			a->count_b++;
		}
	}
	i = 0;
	while (i++ < a->count_b && ft_lstsize(*s_b) != size - a->count_a\
		&& !stack_is_rev_sorted(*s_b))
		command(s_a, s_b, "rrb", 1);
	//exit(0);
	ft_sort(s_a, s_b, a->count_a);
	divide_b(s_a, s_b, size - a->count_a);
}

void		divide_b(t_list **stack_a, t_list **stack_b, int size)
{
	int		i;
	t_div	*a;

	i = 0;
	//printf("### HUNTER SORT HB ###\n\n");
	//printf("# Size = %d\n", size);
	if ((size >= 1 && size <= 2) || check_rev_sort(*stack_b, size))
	{
		while (i++ < size)
			command(stack_a, stack_b, "pa", 1);
		ft_sort(stack_a, stack_b, size);
		return ;
	}
	if (size == 3)
		return (sort_three_b(stack_a, stack_b));
	a = malloc(sizeof(t_div));
	a->mid = middle(*stack_b, size, 0, 2);
	a->count_b = 0;
	a->count_a = 0;
	//printf("# Count_A = %d\n", a->count_a);
	//printf("# Count_B = %d\n", a->count_b);
	div_b_help(stack_a, stack_b, size, a);
	//printf("# Count_A = %d\n", a->count_a);
	//printf("# Count_B = %d\n", a->count_b);

	free(a);
}

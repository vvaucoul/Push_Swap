/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksarnyts <ksarnyts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:13:28 by ksarnyts          #+#    #+#             */
/*   Updated: 2021/03/23 11:48:11 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_just_three_a(t_list **stack_a, t_list **stack_b)
{
	int a;
	int b;
	int c;

	a = *(int *)((*stack_a)->content);
	b = *(int *)((*stack_a)->next->content);
	c = *(int *)((*stack_a)->next->next->content);
	if (a < c && c < b)
	{
		command(stack_a, stack_b, "sa", 1);
		command(stack_a, stack_b, "ra", 1);
	}
	else if (b < a && a < c)
	command(stack_a, stack_b, "sa", 1);
	else if (c < a && a < b)
	command(stack_a, stack_b, "rra", 1);
	else if (b < c && c < a)
	command(stack_a, stack_b, "ra", 1);
	if (c < b && b < a)
	{
		command(stack_a, stack_b, "ra", 1);
		command(stack_a, stack_b, "sa", 1);
	}
}

static void	sort_three_a(t_list **s_a, t_list **s_b)
{
	int a;
	int b;
	int c;

	if (ft_lstsize(*s_a) == 3)
	return (sort_just_three_a(s_a, s_b));
	a = *(int *)((*s_a)->content);
	b = *(int *)((*s_a)->next->content);
	c = *(int *)((*s_a)->next->next->content);
	if (a > b)
	*(int *)((*s_b)->content) < *(int *)((*s_b)->next->content) ?\
	command(s_a, s_b, "ss", 1) : command(s_a, s_b, "sa", 1);
	if (c > a && a > b)
	return ;
	command(s_a, s_b, "ra", 1);
	*(int *)((*s_b)->content) < *(int *)((*s_b)->next->content) ?\
	command(s_a, s_b, "ss", 1) : command(s_a, s_b, "sa", 1);
	command(s_a, s_b, "rra", 1);
	if (b > c && a > c)
	command(s_a, s_b, "sa", 1);
}

void		ft_sort(t_list **stack_a, t_list **stack_b, int size)
{
	int count_b;
	int count_a;

	printf("### HUNTER ALGO ###\n\n");
	printf("# Size = %d\n", size);
	if (size == 1 || check_sort(*stack_a, size))
	return ;
	if (size == 2)
	{
		if (*stack_b && (*stack_b)->next && *(int *)((*stack_b)->content)\
		< *(int *)((*stack_b)->next->content))
		return (command(stack_a, stack_b, "ss", 1));
		return (command(stack_a, stack_b, "sa", 1));
	}
	if (size == 3)
	{
		sort_three_a(stack_a, stack_b);
		//exit(0);
		return ;
	}
	count_a = divide_a(stack_a, stack_b, size); // <-
	printf("# Count_A = %d\n", count_a);
	ft_sort(stack_a, stack_b, count_a); // <-
	count_b = size - count_a; // <-
	printf("# Count_B = %d\n", count_b);
	divide_b(stack_a, stack_b, count_b); // <-
}

static void	ft_lst_cont_clean(void *content, size_t size)
{
	ft_bzero(content, size);
	free(content);
}

int			main(int argc, char **argv)
{
	long int	value;
	t_list		*stack_a;
	t_list		*stack_b;

	if (argc < 2)
	return (0);
	if (check_valid(argc, argv, 1, 0) == 0)
	return (ft_printf("Error\n"));
	stack_a = NULL;
	stack_b = NULL;
	while (argc > 1)
	{
		value = ft_atoi(argv[argc - 1]);
		if (value > 2147483647 || value < -2147483648)
		return (ft_printf("Error\n"));
		if (check_duplicates(stack_a, (int)value))
		return (ft_printf("Error\n"));
		ft_lstadd(&stack_a, ft_lstnew(&value, sizeof(int)));
		argc--;
	}
	ft_sort(&stack_a, &stack_b, ft_lstsize(stack_a)); // <-
	ft_lstdel(&stack_a, &ft_lst_cont_clean);
	return (0);
}

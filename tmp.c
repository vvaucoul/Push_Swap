/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksarnyts <ksarnyts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:18:51 by ksarnyts          #+#    #+#             */
/*   Updated: 2021/03/22 23:55:07 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

}

int			check_duplicates(t_list *stack, int value)
{
	while (stack)
	{
		if (*((int *)stack->content) == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int			check_valid(int ac, char **av, int i, int j)
{
	while (i < ac)
	{
		j = 0;
		if (!ft_isdigit(av[i][j]) && av[i][j] != '-')
			return (0);
		j++;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j++]))
				return (0);
		}
		i++;
	}
	return (1);
}

static void	sort(int *array, int size)
{
	int i;
	int j;
	int tmp;

	i = 1;
	while (i++ < size)
	{
		j = 0;
		while (++j < size)
		{
			if (array[j] < array[j - 1])
			{
				tmp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = tmp;
			}
		}
	}
}

int			middle(t_list *stack, int size, int i, int n)
{
	int *array;
	int mid;

	array = (int *)malloc(sizeof(int) * size);
	while (i < size)
	{
		array[i++] = *((int *)stack->content);
		stack = stack->next;
	}
	sort(array, size);
	mid = array[size / n];
	free(array);
	return (mid);
}















#include "push_swap.h"

void		sort_three_b(t_list **stack_a, t_list **stack_b)
{
	int a;
	int b;
	int c;

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
	(*stack_b) ? (a->flag = 0) : (a->flag = 1);
	a->count_b = 0;
	a->count_a = 0;
	div_a_help(stack_a, stack_b, size, a);
	while (a->count_a-- > 0 && !stack_is_sorted(*stack_a)\
			&& ft_lstsize(*stack_a) != size - a->count_b)
		command(stack_a, stack_b, "rra", 1);
	count = size - a->count_b;
	free(a);
	return (count);
}

static void	div_b_help(t_list **s_a, t_list **s_b, int size, t_div *a)
{
	int i;

	i = 0;
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
	ft_sort(s_a, s_b, a->count_a);
	divide_b(s_a, s_b, size - a->count_a);
}

void		divide_b(t_list **stack_a, t_list **stack_b, int size)
{
	int		i;
	t_div	*a;

	i = 0;
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
	div_b_help(stack_a, stack_b, size, a);
	free(a);
}


















/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksarnyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:18:51 by ksarnyts          #+#    #+#             */
/*   Updated: 2017/02/13 15:19:15 by ksarnyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_list *stack, int size)
{
	int i;

	i = 0;
	while (i++ < size - 1)
	{
		if (*((int *)stack->next->content)\
				< *((int *)stack->content))
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	check_rev_sort(t_list *stack, int size)
{
	int i;

	i = 0;
	while (i++ < size - 1)
	{
		if (*((int *)stack->next->content)\
				> *((int *)stack->content))
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	check_mid_low(t_list *stack, int mid)
{
	while (stack)
	{
		if (*((int *)stack->content) < mid)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	check_mid_up(t_list *stack, int mid)
{
	while (stack)
	{
		if (*((int *)stack->content) >= mid)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	stack_is_rev_sorted(t_list *stack_a)
{
	while (stack_a->next)
	{
		if (*((int *)stack_a->next->content)\
				> *((int *)stack_a->content))
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}
















/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksarnyts <ksarnyts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:13:28 by ksarnyts          #+#    #+#             */
/*   Updated: 2021/03/22 18:44:50 by vvaucoul         ###   ########.fr       */
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
		return (sort_three_a(stack_a, stack_b));
	count_a = divide_a(stack_a, stack_b, size); // <-
	ft_sort(stack_a, stack_b, count_a); // <-
	count_b = size - count_a; // <-
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

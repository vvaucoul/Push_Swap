/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_read_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksarnyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:08:18 by ksarnyts          #+#    #+#             */
/*   Updated: 2017/02/13 16:25:43 by ksarnyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_command(char *com)
{
	if (strcmp(com, "sa") && strcmp(com, "sb")\
			&& strcmp(com, "ss") && strcmp(com, "pa") && strcmp(com, "pb")\
			&& strcmp(com, "ra") && strcmp(com, "rb") && strcmp(com, "rr")\
			&& strcmp(com, "rra") && strcmp(com, "rrb") && strcmp(com, "rrr"))
		return (0);
	return (1);
}

int			read_commands(int pr, int col, t_list **s_a, t_list **s_b)
{
	char	*com;
	int		num;

	num = 0;
	while (get_next_line(0, &com))
	{
		if (com[0] == 0)
		{
			free(com);
			return (num);
		}
		if (!ft_is_command(com))
		{
			free(com);
			return (-1);
		}
		command(s_a, s_b, com, 0);
		num++;
		if (pr && col)
			print_s(*s_a, *s_b, ft_lstsize(*s_a), ft_lstsize(*s_b));
		else if (pr)
			print_c(*s_a, *s_b, ft_lstsize(*s_a), ft_lstsize(*s_b));
		free(com);
	}
	return (num);
}

void		print_s(t_list *stack_a, t_list *stack_b, int s_a, int s_b)
{
	int size;
	int i;

	s_a > s_b ? (size = s_a)\
						: (size = s_b);
	i = -1;
	while (++i < size)
	{
		if (stack_a && i >= size - s_a)
		{
			ft_printf(BLUE "%11d\t", *((int *)stack_a->content));
			stack_a = stack_a->next;
		}
		else
			ft_printf("%11\t");
		if (stack_b && i >= size - s_b)
		{
			ft_printf(GREEN "%11d\n", *((int *)stack_b->content));
			stack_b = stack_b->next;
		}
		else
			ft_printf("%12\n");
	}
	ft_printf(BLUE "%11s\t" GREEN "%11s\n" RESET,\
			"STACK A", "STACK B");
}

void		print_c(t_list *stack_a, t_list *stack_b, int s_a, int s_b)
{
	int size;
	int i;

	s_a > s_b ? (size = s_a)\
						: (size = s_b);
	i = -1;
	while (++i < size)
	{
		if (stack_a && i >= size - s_a)
		{
			ft_printf("%11d\t", *((int *)stack_a->content));
			stack_a = stack_a->next;
		}
		else
			ft_printf("%11\t");
		if (stack_b && i >= size - s_b)
		{
			ft_printf("%11d\n", *((int *)stack_b->content));
			stack_b = stack_b->next;
		}
		else
			ft_printf("%12\n");
	}
	ft_printf("%11s\t%11s\n", "STACK A", "STACK B");
}

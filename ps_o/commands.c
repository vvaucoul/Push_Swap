/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksarnyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:12:07 by ksarnyts          #+#    #+#             */
/*   Updated: 2017/02/13 15:13:14 by ksarnyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **head)
{
	t_list *tmp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	tmp = (*head)->next;
	(*head)->next = tmp->next;
	tmp->next = *head;
	*head = tmp;
}

void	rotate(t_list **head)
{
	t_list *tmp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *head;
	*head = (*head)->next;
	tmp->next->next = NULL;
}

void	reverse(t_list **head)
{
	t_list *tmp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	tmp = *head;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *head;
	*head = tmp->next;
	tmp->next = NULL;
}

void	push(t_list **stack_a, t_list **stack_b)
{
	t_list *b;

	if (*stack_b == NULL)
		return ;
	b = (*stack_b)->next;
	(*stack_b)->next = *stack_a;
	*stack_a = *stack_b;
	*stack_b = b;
}

void	command(t_list **stack_a, t_list **stack_b, char *str, int flag)
{
	static int commands = 0;

	commands++;
	if (flag)
		ft_printf("%s\n", str);
	if (ft_strcmp(str, "sa") == 0 || ft_strcmp(str, "ss") == 0)
		swap(stack_a);
	if (ft_strcmp(str, "sb") == 0 || ft_strcmp(str, "ss") == 0)
		swap(stack_b);
	if (ft_strcmp(str, "pa") == 0)
		push(stack_a, stack_b);
	else if (ft_strcmp(str, "pb") == 0)
		push(stack_b, stack_a);
	if (ft_strcmp(str, "ra") == 0 || ft_strcmp(str, "rr") == 0)
		rotate(stack_a);
	if (ft_strcmp(str, "rb") == 0 || ft_strcmp(str, "rr") == 0)
		rotate(stack_b);
	if (ft_strcmp(str, "rra") == 0 || ft_strcmp(str, "rrr") == 0)
		reverse(stack_a);
	if (ft_strcmp(str, "rrb") == 0 || ft_strcmp(str, "rrr") == 0)
		reverse(stack_b);
}

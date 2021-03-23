/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksarnyts <ksarnyts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:16:06 by ksarnyts          #+#    #+#             */
/*   Updated: 2021/03/23 15:59:31 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "libft/printf/ft_printf.h"
# include <stdio.h>

# define RESET "\x1B[0m"
# define BLUE "\x1B[34m"
# define GREEN "\x1B[32m"
# define RED "\x1B[31m"

typedef struct	s_div
{
	int mid;
	int mid_b;
	int count_b;
	int count_a;
	int flag;
}				t_div;

void			command(t_list **stack_a, t_list **stack_b, char *str,\
				int flag);
void			swap(t_list **head);
void			rotate(t_list **head);
void			reverse(t_list **head);
void			push(t_list **stack_a, t_list **stack_b);
int				check_valid(int ac, char **av, int i, int j);
int				read_commands(int pr, int col, t_list **stack_a,\
				t_list **stack_b);
int				check_duplicates(t_list *stack, int value);
void			print_s(t_list *stack_a, t_list *stack_b, int s_a, int s_b);
void			print_c(t_list *stack_a, t_list *stack_b, int s_a, int s_b);
int				stack_is_sorted(t_list *stack_a);
int				stack_is_rev_sorted(t_list *stack_a);
void			ft_sort(t_list **stack_a, t_list **stack_b, int size);
int				middle(t_list *stack, int size, int i, int n);
int				check_sort(t_list *stack, int size);
int				check_rev_sort(t_list *stack, int size);
int				check_mid_low(t_list *stack, int mid);
int				check_mid_up(t_list *stack, int mid);
int				divide_a(t_list **stack_a, t_list **stack_b, int size);
void			divide_b(t_list **stack_a, t_list **stack_b, int size);

#endif

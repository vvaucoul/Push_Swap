/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksarnyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:09:48 by ksarnyts          #+#    #+#             */
/*   Updated: 2017/02/13 16:43:27 by ksarnyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	read_all_flags(char *str, int *flags)
{
	int i;

	if (str[0] != '-')
		return (0);
	i = 1;
	while (i < 4)
	{
		if (str[i] == 'v' && !flags[0])
			flags[0] = 1;
		else if (str[i] == 'c' && !flags[1])
			flags[1] = 1;
		else if (str[i] == 'n' && !flags[2])
			flags[2] = 1;
		else if (str[i] == '\0' && i >= 3)
			return (1);
		else
			return (0);
		i++;
	}
	if (str[i] == '\0')
		return (1);
	return (0);
}

static int	*read_flags(int ac, char **av, int *n)
{
	int *flags;

	flags = ft_memalloc(3 * sizeof(int));
	*n = 2;
	if (read_all_flags(av[1], flags))
		return (flags);
	*n = 1;
	while (*n < ac && *n < 4)
	{
		if (av[*n][0] != '-')
			return (flags);
		if (av[*n][1] == 'v' && av[*n][2] == '\0')
			flags[0] = 1;
		else if (av[*n][1] == 'c' && av[*n][2] == '\0')
			flags[1] = 1;
		else if (av[*n][1] == 'n' && av[*n][2] == '\0')
			flags[2] = 1;
		else
			return (flags);
		(*n)++;
	}
	return (flags);
}

static int	create_list(int argc, char **argv, t_list **stack_a, int n)
{
	long int value;

	while (argc > n)
	{
		value = ft_atoi(argv[argc - 1]);
		if (value > 2147483647 || value < -2147483648)
			return (ft_printf("Error\n"));
		if (check_duplicates(*stack_a, (int)value))
			return (ft_printf("Error\n"));
		ft_lstadd(stack_a, ft_lstnew(&value, sizeof(int)));
		argc--;
	}
	return (1);
}

void		print_ok(t_list *s_a, t_list *s_b, int *flags, int commands)
{
	if (stack_is_sorted(s_a) && s_b == NULL)
		flags[1] ? ft_printf(GREEN "%13cOK\n" RESET, ' ') :\
			ft_printf("%13cOK\n", ' ');
	else
		flags[1] ? ft_printf(RED "%14KO\n" RESET) :\
			ft_printf("%14KO\n");
	if (flags[2])
		ft_printf("used commands: %d\n", commands);
}

int			main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		commands;
	int		*flags;
	int		n;

	if (argc < 2)
		return (0);
	flags = read_flags(argc, argv, &n);
	if (check_valid(argc, argv, n, 0) == 0)
		return (ft_printf("Error\n"));
	stack_a = NULL;
	stack_b = NULL;
	if (create_list(argc, argv, &stack_a, n) > 1)
		return (1);
	if ((commands = read_commands(flags[0], flags[1], &stack_a,\
					&stack_b)) == -1)
		return (ft_printf("Error\n"));
	print_ok(stack_a, stack_b, flags, commands);
	return (0);
}

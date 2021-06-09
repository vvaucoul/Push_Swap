/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 21:59:41 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/19 15:42:20 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core_bonus.h"

/*
** Bonus function
** Remove all bonus flag for non bonus
*/

static int		get_valid_arg(char **tab)
{
	int i;
	int valid;

	i = 0;
	valid = 0;
	while (tab[i])
	{
		if (!(is_valid_arg(tab[i])) && (is_bonus_flag(tab[i])))
			++valid;
		++i;
	}
	return (valid);
}

static int		init_bonus_arg(t_val *val, int size, char **argv)
{
	int i;

	i = 0;
	val->print_output = 0;
	val->bonus_visualize = 0;
	val->bonus_last_change = 0;
	while (i < size)
	{
		if (!(is_bonus_flag(argv[i])))
		{
			if (!(ft_strcmp(argv[i], "-c")))
			{
				val->print_output = 1;
				val->bonus_visualize = 1;
			}
			else if (!(ft_strcmp(argv[i], "-v")))
				val->bonus_last_change = 1;
		}
		++i;
	}
	return (0);
}

/*
** Init Struct
*/

static void		assign_heaps(t_val *val, int size, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		if (!(is_valid_arg(argv[i])) && (is_bonus_flag(argv[i])))
		{
			val->a[j] = ft_atoi(argv[i]);
			val->b[j] = 0;
			++j;
		}
		++i;
	}
	val->a[j] = 0;
}

static t_val	*init_struct(int size, char **argv)
{
	static t_val	val;

	if (!(val.a = (int *)malloc(sizeof(int) * (size + 1))))
		return (NULL);
	if (!(val.b = (int *)malloc(sizeof(int) * (size + 1))))
		return (NULL);
	assign_heaps(&val, size, argv);
	val.size_a = (size_t)get_valid_arg(argv);
	val.size_b = 0;
	val.nb_operation = 0;
	val.print_output = 0;
	init_bonus_arg(&val, size, argv);
	return (&val);
}

t_val			*init_param(int argc, char **argv)
{
	char	**tab;
	int		i;
	int		error;

	i = 0;
	if (argc <= 1)
		return (NULL);
	if (!(tab = parse_arg(argc, argv)))
		return (NULL);
	while (tab[i])
	{
		if ((error = (is_valid_arg(tab[i]))))
		{
			print_error(error == 1 ? "Error : Non numeric character found\n" :
			"Error : Number invalid, > to INTMAX\n", 1);
			return (free_tab(tab, NULL));
		}
		++i;
	}
	if (has_doublon(tab))
	{
		print_error("Error : Doublon found\n", 1);
		return (free_tab(tab, NULL));
	}
	return ((free_tab(tab, init_struct(ft_ctablen(tab), tab))));
}

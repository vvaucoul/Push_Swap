/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:23:56 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/19 15:53:39 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/core_bonus.h"

static int		get_operation(const char *str)
{
	if (!(ft_strcmp(str, "sa")))
		return (0);
	if (!(ft_strcmp(str, "sb")))
		return (1);
	if (!(ft_strcmp(str, "ss")))
		return (2);
	if (!(ft_strcmp(str, "pa")))
		return (3);
	if (!(ft_strcmp(str, "pb")))
		return (4);
	if (!(ft_strcmp(str, "ra")))
		return (5);
	if (!(ft_strcmp(str, "rb")))
		return (6);
	if (!(ft_strcmp(str, "rr")))
		return (7);
	if (!(ft_strcmp(str, "rra")))
		return (8);
	if (!(ft_strcmp(str, "rrb")))
		return (9);
	if (!(ft_strcmp(str, "rrr")))
		return (10);
	return (-1);
}

static void		init_array(int (*operations[11])(t_val *val))
{
	operations[0] = sa;
	operations[1] = sb;
	operations[2] = ss;
	operations[3] = pa;
	operations[4] = pb;
	operations[5] = ra;
	operations[6] = rb;
	operations[7] = rr;
	operations[8] = rra;
	operations[9] = rrb;
	operations[10] = rrr;
}

/*
** //operations = (t_val *){sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr};
*/

/*
** Bonus visualisation : ajouter la visualisation apres ligne 81
** ++val->nb_operation...
*/

static int		compare_input(t_val *val, const char *str)
{
	int (*operations[11])(t_val *val);
	int execute;

	init_array(operations);
	if ((execute = get_operation(str)) < 0)
	{
		print_error("Error : [", 1);
		print_error(str, 1);
		print_error("] invalid command\n", 1);
		return (1);
	}
	else
	{
		operations[execute](val);
		++val->nb_operation;
		// ajouter previsualisation
		update_visualisation(val);
		usleep(DEBUG_TIME_TO_WAIT);
	}
	return (0);
}

static int		print_result(t_val *val, int solved)
{
	if (solved == 1)
	{
		write(1, GREEN, ft_strlen(GREEN));
		ft_putstr_fd("\t- RESULT : [OK]\n", 1);
	}
	else
	{
		write(1, RED, ft_strlen(RED));
		ft_putstr_fd("\t- RESULT : [KO]\n", 1);
	}
	write(1, YELLOW, ft_strlen(YELLOW));
	ft_putstr_fd("\t- Nombre de coups : [", 1);
	ft_putnbr_fd(val->nb_operation, 1);
	write(1, "]\n", 2);
	ft_putstr_fd(solved ? (SUCCESS) : (FAILURE), 1);
	print_heaps(val);
	return (0);
}

int				read_input(t_val *val)
{
	int		solved;
	char	str[4096];
	int		i;
	char	buffer;
	int		fc;

	solved = 0;
	fc = 1;
	while (fc != 0)
	{
		buffer = 0;
		str[0] = 0;
		i = 0;
		while (buffer != '\n' && fc != 0)
		{
			fc = read(DEFAULT_CHECKER_READ_INPUT, &buffer, 1);
			str[i] = buffer;
			++i;
		}
		str[i - 1] = 0;
		if (fc > 0 && *str && str[0] != 0 && str[0] != '\n')
			compare_input(val, str);
		solved = ((heap_solved(val) == 1) ? 0 : 1);
	}
	return (print_result(val, solved));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:23:56 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/24 13:02:58 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

/*
** //operations = (t_val *){sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr};
*/

static int		compare_input(t_val *val, const char *str)
{
	int (*operations[11])(t_val *val, t_bool print);
	int execute;

	init_array(operations);
	if ((execute = get_operation(str)) < 0)
	{
		print_error("Error : [", 1);
		print_error(str, 1);
		print_error("] invalid command\n", 1);
		return (2);
	}
	else
	{
		operations[execute](val, FALSE);
		++val->nb_operation;
		if ((update_visualisation(val, execute)))
			return (1);
	}
	return (0);
}

static int		print_result(t_val *val, int solved)
{
	if (solved == 1)
		ft_putstr_fd(GREEN"\n\t- RESULT : [OK]\n", 1);
	else
		ft_putstr_fd(RED"\n\t- RESULT : [KO]\n", 1);
	ft_putstr_fd(YELLOW"\t- Nombre de coups : [", 1);
	ft_putnbr_fd(val->nb_operation, 1);
	write(1, "]\n", 2);
	ft_putstr_fd(solved ? (SUCCESS) : (FAILURE), 1);
	print_heaps(val);
	return (0);
}

static int		read_input_init_values(t_val *val,
char *buffer, int *i, char str[])
{
	if ((update_visualisation(val, -1)))
		return (1);
	i[0] = 0;
	buffer[0] = 0;
	str[0] = 0;
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
		if ((read_input_init_values(val, &buffer, &i, str)) == 1)
			return (1);
		while (buffer != '\n' && fc != 0)
		{
			fc = read(DEFAULT_CHECKER_READ_INPUT, &buffer, 1);
			str[i] = buffer;
			++i;
		}
		str[i - 1] = 0;
		if (fc > 0 && *str && str[0] != 0 && str[0] != '\n')
			if ((compare_input(val, str)) == 1)
				return (1);
		solved = ((heap_solved(val) == 1) ? 0 : 1);
	}
	return (print_result(val, solved));
}

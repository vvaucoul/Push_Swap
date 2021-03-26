/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 18:06:35 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/24 11:34:44 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int			get_operation(const char *str)
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

void		init_array(int (*operations[11])(t_val *val, t_bool print))
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

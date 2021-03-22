/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:55:18 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/20 18:09:31 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
** Push swap Main
**
** val->bonus_visualize = 1;
** val->bonus_last_change = 0;
** val->print_output = 1;
*/

int	main(int argc, char **argv)
{
	t_val *val;

	if ((val = init_param(argc, argv)) == NULL)
		return (1);
	val->print_output = 1;
	solve_heap(val);
	free_val(val);
	return (0);
}

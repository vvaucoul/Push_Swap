/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:31:56 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/19 15:52:51 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/core_bonus.h"

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

	printf("push swap bonus\n");
	if ((val = init_param(argc, argv)) == NULL)
		return (1);
	val->print_output = 1;
	solve_heap(val);
	free_val(val);
	return (0);
}

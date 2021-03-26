/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 21:58:09 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/24 13:23:44 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int	main(int argc, char **argv)
{
	t_val *val;

	if ((val = init_param(argc, argv)) == NULL)
		return (1);
	if ((read_input(val)))
	{
		free_val(val);
		return (print_error(RED"- Use terminal size more than 54/16\n", 1));
	}
	val->bonus_visualize = 1;
	print_heaps(val);
	free_val(val);
}

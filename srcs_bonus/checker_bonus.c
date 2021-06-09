/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:33:00 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/19 15:50:03 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/core_bonus.h"

int	main(int argc, char **argv)
{
	t_val *val;

	printf("push swap bonus\n");
	if ((val = init_param(argc, argv)) == NULL)
		return (1);
	read_input(val);
	free_val(val);
}

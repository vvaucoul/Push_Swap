/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 21:58:09 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/19 13:35:24 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int	main(int argc, char **argv)
{
	t_val *val;

	if ((val = init_param(argc, argv)) == NULL)
		return (1);
	read_input(val);
	free_val(val);
}

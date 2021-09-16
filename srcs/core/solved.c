/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solved.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:38:14 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/23 10:12:26 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int	heap_solved(t_val *val)
{
	size_t i;

	i = 0;
	if (val->size_b > 0)
		return (1);
	while (i < (val->size_a - 1))
	{
		if (i >= (val->size_a - 1))
			break ;
		if (val->a[i] > val->a[i + 1])
			return (1);
		++i;
	}
	return (0);
}

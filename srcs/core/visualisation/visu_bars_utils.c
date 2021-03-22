/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_bars_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:36:56 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/20 19:10:07 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/checker.h"

/*
** int value, int old_min, int old_max, int new_min, int new_max
*/

int		map_range_clamped(t_range range)
{
	range.value = range.value <= 0 ? 1 : range.value;
	range.old_max = range.old_max <= 0 ? 1 : range.old_max;
	range.old_min = range.old_min <= 0 ? 1 : range.old_min;
	return ((((range.value - range.old_min) * (range.new_max - range.new_min)) /
	((range.old_max - range.old_min <= 0 ? 1 : range.old_max - range.old_min)))
	+ range.new_min);
}

void	select_color(int size)
{
	if (size >= 20)
		ft_putstr_fd(GREEN, 1);
	else if (size >= 10)
		ft_putstr_fd(YELLOW, 1);
	else
		ft_putstr_fd(RED, 1);
}

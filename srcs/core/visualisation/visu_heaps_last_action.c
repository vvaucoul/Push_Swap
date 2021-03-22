/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_heaps_last_action.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 19:12:28 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/20 20:19:48 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/checker.h"

/*
** ACTION :
**
** - SA : 0
** - SB : 1
** - SS : 2
** - PA : 3
** - PB : 4
** - RA : 5
** - RB : 6
** - RR : 7
** - RRA : 8
** - RRB : 9
** - RRR : 10
*/

void			update_last_action_heap_a(t_val *val, int action, int i)
{
	if (action < 0 || !val->bonus_last_change)
		return ;
	if ((action == 0 || action == 2) && i == 0)
	{
		ft_putstr_fd(YELLOW, 1);
		ft_putstr_fd("-> ", 1);
	}
	if (action == 3 && i == 0)
	{
		ft_putstr_fd(YELLOW, 1);
		ft_putstr_fd("-> ", 1);
	}
	if ((action == 5 || action == 7) && i == 0)
	{
		ft_putstr_fd(YELLOW, 1);
		ft_putstr_fd("^ ", 1);
	}
	if ((action == 8 || action == 10) && i == (int)val->size_a - 1)
	{
		ft_putstr_fd(YELLOW, 1);
		ft_putstr_fd("v ", 1);
	}
	ft_putstr_fd(GREEN, 1);
}

void			update_last_color_action_heap_a(t_val *val, int action, int i)
{
	if (!val->bonus_last_change)
		return ;
	(void)action;
	(void)i;
}

void			update_last_action_heap_b(t_val *val, int action, int i)
{
	if (action < 0 || !val->bonus_last_change)
		return ;
	if ((action == 1 || action == 2) && i == 0)
	{
		ft_putstr_fd(YELLOW, 1);
		ft_putstr_fd("-> ", 1);
	}
	if (action == 4 && i == 0)
	{
		ft_putstr_fd(YELLOW, 1);
		ft_putstr_fd("-> ", 1);
	}
	if ((action == 6 || action == 7) && i == 0)
	{
		ft_putstr_fd(YELLOW, 1);
		ft_putstr_fd("^ ", 1);
	}
	if ((action == 9 || action == 10) && i == (int)val->size_b - 1)
	{
		ft_putstr_fd(YELLOW, 1);
		ft_putstr_fd("v ", 1);
	}
	ft_putstr_fd(GREEN, 1);
}

void			update_last_color_action_heap_b(t_val *val, int action, int i)
{
	if (!val->bonus_last_change)
		return ;
	(void)action;
	(void)i;
}

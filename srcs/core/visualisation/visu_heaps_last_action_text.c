/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_heaps_last_action_text.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 20:01:53 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/20 20:19:58 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/checker.h"

static void		update_last_text_02(t_val *val, int action)
{
	(void)val;
	if (action == 4)
		ft_putstr_fd("PB", 1);
	if (action == 5)
		ft_putstr_fd("RA", 1);
	if (action == 6)
		ft_putstr_fd("RB", 1);
	if (action == 7)
		ft_putstr_fd("RR", 1);
	if (action == 8)
		ft_putstr_fd("RRA", 1);
	if (action == 9)
		ft_putstr_fd("RRB", 1);
	if (action == 10)
		ft_putstr_fd("RRR", 1);
}

void			update_last_text(t_val *val, int action)
{
	if (!val->bonus_last_change)
		return ;
	ft_putstr_fd(YELLOW, 1);
	ft_putstr_fd("\t - Last action : [", 1);
	if (action == 0)
		ft_putstr_fd("SA", 1);
	if (action == 1)
		ft_putstr_fd("SB", 1);
	if (action == 2)
		ft_putstr_fd("SS", 1);
	if (action == 3)
		ft_putstr_fd("PA", 1);
	update_last_text_02(val, action);
	ft_putstr_fd("]\n", 1);
}

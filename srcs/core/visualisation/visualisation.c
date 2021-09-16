/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualisation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:49:42 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/20 20:06:58 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/checker.h"

int		update_visualisation(t_val *val, int action)
{
	t_term term;

	if (!val->bonus_visualize)
		return (0);
	if (init_term(&term))
		return (1);
	if (!val->display_bar)
		preview_heaps(val, term, action);
	else
		preview_bar(val, term, action);
	usleep(DEBUG_TIME_TO_WAIT);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_heaps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:06:36 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/21 11:23:08 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/checker.h"

static void		init_str_values(t_val *val, UINT i, int action)
{
	char			*tmp;

	if (val->size_a > i)
	{
		update_last_action_heap_a(val, action, i);
		update_last_color_action_heap_a(val, action, i);
		tmp = ft_itoa(val->a[i]);
		ft_putstr_fd(tmp, 1);
		free(tmp);
	}
	else
		ft_putstr_fd(".", 1);
	ft_putstr_fd("\t\t", 1);
	if (val->size_b > i)
	{
		update_last_action_heap_b(val, action, i);
		update_last_color_action_heap_b(val, action, i);
		tmp = ft_itoa(val->b[i]);
		ft_putstr_fd(tmp, 1);
		free(tmp);
	}
	else
		ft_putstr_fd(".", 1);
}

static void		draw_heap(t_val *val, t_term term, int action)
{
	static UINT		mi = 0;
	UINT			i;

	i = 0;
	if (mi == 0)
		mi = val->size_a;
	while (i < mi)
	{
		v_draw_str(' ', v_get_special_position(term.term_x / 2) -
		(ft_strlen(HEADER) / 2) + ((ft_strlen("- HEAP A -") / 2) - 2), FALSE);
		ft_putstr_fd(GREEN, 1);
		init_str_values(val, i, action);
		ft_putstr_fd("\n", 1);
		++i;
	}
}

void			preview_heaps(t_val *val, t_term term, int action)
{
	clear_screen();
	ft_putstr_fd(BLUE, 1);
	v_draw_str('#', term.term_x, TRUE);
	v_draw_str(' ', (v_get_center_position(term, HEADER, 0)), FALSE);
	ft_putstr_fd(RED, 1);
	ft_putstr_fd(HEADER, 1);
	ft_putstr_fd("\n\n", 1);
	draw_heap(val, term, action);
	ft_putstr_fd(YELLOW, 1);
	ft_putstr_fd("\n", 1);
	v_draw_str(' ', (v_get_center_position(term, HEADER, ft_strlen(HEADER) / 2))
	, FALSE);
	ft_putstr_fd(YELLOW, 1);
	ft_putstr_fd("\tNombre de coups Actuels : [", 1);
	ft_putnbr_fd(val->nb_operation, 1);
	ft_putstr_fd("]\n", 1);
	ft_putstr_fd(NORMAL, 1);
	v_draw_str(' ', (v_get_center_position(term, HEADER, ft_strlen(HEADER) / 2))
	, FALSE);
	update_last_text(val, action);
	usleep(DEBUG_TIME_TO_WAIT);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_bars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:32:37 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/21 11:23:20 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/checker.h"

/*
** MIN / MAX Functions
*/

static int			get_max_value(int *h)
{
	int max;
	int i;

	i = 0;
	max = h[0];
	while (h[i])
	{
		if (h[i] > max)
			max = h[i];
		++i;
	}
	return (max);
}

static int			get_min_value(int *h)
{
	int min;
	int i;

	i = 0;
	min = h[0];
	while (h[i])
	{
		if (h[i] < min)
			min = h[i];
		++i;
	}
	return (min);
}

static void			draw_bars_heap_a(t_val *val, t_term term, UINT i)
{
	int				j;
	int				max_x;

	j = 0;
	v_draw_str(' ', (v_get_left_position(term, HEADER, 12)), FALSE);
	if (val->size_a > i)
	{
		max_x = map_range_clamped((t_range){val->a[i],
		get_min_value(val->a), get_max_value(val->a), BAR_MIN, BAR_MAX});
		while (j < max_x)
		{
			select_color(max_x);
			ft_putstr_fd(YELLOW, 1);
			ft_putstr_fd("#", 1);
			++j;
		}
		j = 0;
		while (j < (BAR_MAX - max_x) + (BAR_MAX / 2))
		{
			ft_putstr_fd(" ", 1);
			++j;
		}
	}
}

static void			draw_bars(t_val *val, t_term term)
{
	static UINT		mi = 0;
	UINT			i;
	int				j;
	int				max_x;

	i = -1;
	if (mi == 0)
		mi = val->size_a;
	while (++i < mi)
	{
		draw_bars_heap_a(val, term, i);
		j = -1;
		if (val->size_b > i)
		{
			max_x = map_range_clamped((t_range){val->b[i],
			get_min_value(val->b), get_max_value(val->b), BAR_MIN, BAR_MAX});
			while (++j < max_x)
			{
				select_color(max_x);
				ft_putstr_fd(YELLOW, 1);
				ft_putstr_fd("#", 1);
			}
		}
		ft_putstr_fd("\n", 1);
	}
}

void				preview_bar(t_val *val, t_term term, int action)
{
	clear_screen();
	ft_putstr_fd(BLUE, 1);
	v_draw_str('#', term.term_x, TRUE);
	v_draw_str(' ', (v_get_center_position(term, HEADER, 0)), FALSE);
	ft_putstr_fd(RED, 1);
	ft_putstr_fd(HEADER, 1);
	ft_putstr_fd("\n\n", 1);
	draw_bars(val, term);
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

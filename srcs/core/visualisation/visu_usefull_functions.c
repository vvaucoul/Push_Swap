/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_usefull_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:36:39 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/20 13:59:17 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/checker.h"

void		v_draw_str(char c, UINT n, t_bool newline)
{
	UINT i;

	i = 0;
	while (i < n)
	{
		ft_putchar_fd(c, 1);
		++i;
	}
	if (newline)
		ft_putchar_fd('\n', 1);
}

UINT		v_get_left_position(t_term term, char *str, UINT decal)
{
	return ((term.term_x / 2) - (ft_strlen(str) + decal));
}

UINT		v_get_right_position(t_term term, char *str, UINT decal)
{
	return ((term.term_x / 2) + (ft_strlen(str) + decal));
}

UINT		v_get_center_position(t_term term, char *str, UINT decal)
{
	return ((term.term_x / 2) - ((ft_strlen(str) / 2) + decal));
}

UINT		v_get_special_position(UINT decal)
{
	return (decal);
}

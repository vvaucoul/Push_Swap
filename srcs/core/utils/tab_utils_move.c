/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:23:58 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/20 18:51:24 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/core.h"

int			*ft_move_tab_down(int *tab, size_t *size)
{
	int i;

	i = (*size);
	if (i < 0)
		i = 0;
	while (i > 0)
	{
		if (i <= 0)
			break ;
		tab[i] = tab[i - 1];
		--i;
	}
	tab[0] = 0;
	++(*size);
	return (tab);
}

int			*ft_move_tab_up(int *tab, size_t *size)
{
	UINT i;

	i = 0;
	while (i < *size)
	{
		if (i >= *size)
			break ;
		tab[i] = tab[i + 1];
		++i;
	}
	--(*size);
	return (tab);
}

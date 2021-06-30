/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:15:57 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/19 15:24:53 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/core.h"

size_t		ft_tablen(const int *str)
{
	size_t i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		++i;
	return (i);
}

int			*ft_realloc_int(int *tab, int new_size)
{
	int *tmp;
	int i;
	int len;

	i = 0;
	len = ft_tablen(tab);
	if (!tab)
		return (NULL);
	if (!(tmp = malloc(sizeof(int) * (new_size + 1))))
		return (NULL);
	while (i < new_size)
	{
		if (i < len)
			tmp[i] = tab[i];
		else
			tmp[i] = 0;
		++i;
	}
	tmp[i] = 0;
	free(tab);
	i = 0;
	return (tmp);
}

size_t		ft_fulltablen(char **tab)
{
	int mx;
	int x;
	int y;

	x = 0;
	y = 0;
	mx = 0;
	while (tab[y])
	{
		while (tab[y][x])
			++x;
		if (x > mx)
			mx = x;
		++y;
		x = 0;
	}
	return ((y <= 0 ? 1 : y) * mx);
}

size_t		ft_ctablen(char **tab)
{
	size_t i;

	i = 0;
	while (tab[i])
		++i;
	return (i);
}

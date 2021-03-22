/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:28:59 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/19 15:22:03 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/core.h"

int			ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

static int	skipuselesschar(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\t'
	|| str[i] == '\n'
	|| str[i] == '\v'
	|| str[i] == '\r'
	|| str[i] == '\f'
	|| str[i] == ' ')
		++i;
	return (i);
}

int			ft_atoi(const char *str)
{
	int		result;
	int		isneg;
	size_t	i;

	result = 0;
	i = skipuselesschar(str);
	isneg = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		isneg = (str[i] == '-' ? 1 : 0);
		++i;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		result = result * 10 + str[i] - 48;
		++i;
	}
	return (isneg == 1 ? result *= -1 : result);
}

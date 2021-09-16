/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoull.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 11:00:52 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/21 11:03:51 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/core.h"

static int					skipuselesschar(const char *str)
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

long long					ft_atoull(const char *str)
{
	long long				result;
	int						isneg;
	size_t					i;

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

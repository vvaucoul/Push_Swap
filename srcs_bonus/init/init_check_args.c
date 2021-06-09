/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_check_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:14:38 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/19 15:50:34 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core_bonus.h"

int		is_bonus_flag(const char *str)
{
	char	*flags[3];
	int		i;

	flags[0] = "-c";
	flags[1] = "-v";
	flags[2] = NULL;
	i = 0;
	while (flags[i])
	{
		if (!(ft_strcmp(str, flags[i])))
			return (0);
		++i;
	}
	return (1);
}

int		is_valid_arg(const char *str)
{
	int i;

	i = 0;
	if (!(is_bonus_flag(str)))
		return (0);
	if (str[0] == '-' || str[0] == '+')
		++i;
	if (!str[i])
		return (1);
	else
	{
		while (str[i])
		{
			if (str[i] < '0' || str[i] > '9')
				return (1);
			++i;
		}
	}
	if ((unsigned long long)ft_atoi(str) > 2147483647)
		return (2);
	return (0);
}

int		has_doublon(char **tab)
{
	char	*doublons[4096];
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (tab[++i])
		doublons[i] = tab[i];
	doublons[i] = NULL;
	if (i <= 1)
		return (0);
	i = 0;
	while (doublons[i])
	{
		while (tab[j])
		{
			if (i != j)
				if (!(ft_strcmp(doublons[i], tab[j])))
					return (1);
			++j;
		}
		++i;
		j = 0;
	}
	return (0);
}

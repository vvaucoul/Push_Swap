/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:45:45 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/20 11:53:40 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/core.h"

char		*assign_line(char *str, int *start)
{
	char	tmp[4096];
	int		i;
	int		save_start;

	save_start = *start;
	i = 0;
	while (str[*start])
	{
		if (str[*start] == ' ')
			break ;
		++(*start);
	}
	while (save_start != *start)
	{
		tmp[i] = str[save_start];
		++save_start;
		++i;
	}
	tmp[i] = 0;
	return (ft_strdup(tmp));
}

char		**parse_arg(int argc, char **argv)
{
	char	**tab;
	int		i;
	int		j;
	int		y;

	i = 1;
	y = 0;
	if (!(tab = malloc(sizeof(char *) * (ft_fulltablen(argv)))))
		return (NULL);
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			tab[y] = assign_line(argv[i], &j);
			while (argv[i][j] != ' ' && argv[i][j])
				++j;
			while (argv[i][j] == ' ' && argv[i][j])
				++j;
			++y;
		}
		++i;
	}
	tab[y] = NULL;
	return (tab);
}

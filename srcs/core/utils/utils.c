/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 22:05:53 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/19 15:24:28 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/core.h"

void		ft_putstr_fd(const char *str, int fd)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar_fd(str[i], fd);
		++i;
	}
}

int			print_error(const char *str, int error)
{
	write(2, str, ft_strlen(str));
	return (error);
}

void		print_output(t_val *val, const char *str)
{
	if (val->print_output)
	{
		write(1, str, ft_strlen(str));
		write(1, "\n", 1);
	}
}

void		print_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_putnbr_fd(i, 1);
		ft_putstr_fd(": ", 1);
		ft_putstr_fd(tab[i], 1);
		ft_putstr_fd("\n", 1);
		++i;
	}
}

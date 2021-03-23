/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksarnyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:46:05 by ksarnyts          #+#    #+#             */
/*   Updated: 2016/11/22 11:50:38 by ksarnyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int un;

	if (n < 0)
	{
		ft_putchar('-');
		un = -n;
	}
	else
		un = n;
	if (un >= 10)
	{
		ft_putnbr(un / 10);
		ft_putnbr(un % 10);
	}
	else
		ft_putchar(un + '0');
}

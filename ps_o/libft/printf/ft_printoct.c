/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printoct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksarnyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 13:39:27 by ksarnyts          #+#    #+#             */
/*   Updated: 2017/01/14 17:25:36 by ksarnyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printoct(int n)
{
	unsigned int nb;

	nb = n;
	if (nb >= 8)
	{
		ft_printoct(nb / 8);
		ft_printoct(nb % 8);
	}
	else
		ft_pputchar(nb + 48);
}

void	ft_printloct(long int n)
{
	unsigned long int nb;

	nb = n;
	if (nb >= 8)
	{
		ft_printloct(nb / 8);
		ft_printloct(nb % 8);
	}
	else
		ft_pputchar(nb + 48);
}

void	ft_printuloct(unsigned long long int n)
{
	if (n >= 8)
	{
		ft_printloct(n / 8);
		ft_printloct(n % 8);
	}
	else
		ft_pputchar(n + 48);
}

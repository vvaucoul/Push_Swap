/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksarnyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:46:05 by ksarnyts          #+#    #+#             */
/*   Updated: 2017/01/15 19:14:16 by ksarnyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pputnbr(int n)
{
	unsigned int un;

	if (n < 0)
	{
		ft_pputchar('-');
		un = -n;
	}
	else
		un = n;
	if (un >= 10)
	{
		ft_pputnbr(un / 10);
		ft_pputnbr(un % 10);
	}
	else
		ft_pputchar(un + '0');
}

void	ft_printunbr(unsigned int n)
{
	if (n >= 10)
	{
		ft_printunbr(n / 10);
		ft_printunbr(n % 10);
	}
	else
		ft_pputchar(n + 48);
}

void	ft_printlnbr(long int n)
{
	unsigned long int un;

	if (n < 0)
	{
		ft_pputchar('-');
		un = -n;
	}
	else
		un = n;
	if (un >= 10)
	{
		ft_printlnbr(un / 10);
		ft_printlnbr(un % 10);
	}
	else
		ft_pputchar(un + '0');
}

void	ft_printulnbr(unsigned long int n)
{
	if (n >= 10)
	{
		ft_printulnbr(n / 10);
		ft_printulnbr(n % 10);
	}
	else
		ft_pputchar(n + 48);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksarnyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 12:58:10 by ksarnyts          #+#    #+#             */
/*   Updated: 2017/01/15 19:12:08 by ksarnyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printhex(int n, char c)
{
	unsigned int	nb;
	char			*base_x;
	char			*base_xx;

	base_x = "0123456789abcdef";
	base_xx = "0123456789ABCDEF";
	nb = n;
	if (nb >= 16)
	{
		ft_printhex(nb / 16, c);
		ft_printhex(nb % 16, c);
	}
	else
	{
		if (c == 'x')
			ft_pputchar(base_x[nb]);
		else
			ft_pputchar(base_xx[nb]);
	}
}

void	ft_printulhex(unsigned long long int n, char c)
{
	char *base_x;
	char *base_xx;

	base_x = "0123456789abcdef";
	base_xx = "0123456789ABCDEF";
	if (n >= 16)
	{
		ft_printulhex(n / 16, c);
		ft_printulhex(n % 16, c);
	}
	else
	{
		if (c == 'x')
			ft_pputchar(base_x[n]);
		else
			ft_pputchar(base_xx[n]);
	}
}

void	ft_printaddr(unsigned long int n)
{
	char *base;

	base = "0123456789abcdef";
	if (n >= 16)
	{
		ft_printaddr(n / 16);
		ft_printaddr(n % 16);
	}
	else
		ft_pputchar(base[n]);
}

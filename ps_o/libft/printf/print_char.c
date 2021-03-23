/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksarnyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 15:45:24 by ksarnyts          #+#    #+#             */
/*   Updated: 2017/01/15 19:17:22 by ksarnyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_help_c(int *mod_array, char c)
{
	if (mod_array[8] == 0 || mod_array[4])
	{
		if (mod_array[4] == 0)
		{
			while (mod_array[9]-- > 1)
				ft_pputchar(' ');
		}
		ft_pputchar(c);
		if (mod_array[4] != 0)
		{
			while (mod_array[9]-- > 1)
				ft_pputchar(' ');
		}
		return ;
	}
	while (mod_array[9]-- > 1)
		ft_pputchar('0');
	ft_pputchar(c);
}

void		ft_print_c(int *mod_array, va_list ap)
{
	char c;

	c = (char)va_arg(ap, int);
	ft_help_c(mod_array, c);
}

static void	ft_help_wc(int *mod_array, wchar_t c)
{
	if (mod_array[8] == 0 || mod_array[4])
	{
		if (mod_array[4] == 0)
		{
			while (mod_array[9]-- > 1)
				ft_pputchar(' ');
		}
		ft_putwchar(c);
		if (mod_array[4] != 0)
		{
			while (mod_array[9]-- > 1)
				ft_pputchar(' ');
		}
		return ;
	}
	while (mod_array[9]-- > 1)
		ft_pputchar('0');
	ft_putwchar(c);
}

void		ft_print_wc(int *mod_array, va_list ap)
{
	wchar_t c;

	c = va_arg(ap, wchar_t);
	ft_help_wc(mod_array, c);
}

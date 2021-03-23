/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksarnyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 18:15:23 by ksarnyts          #+#    #+#             */
/*   Updated: 2017/01/16 16:05:28 by ksarnyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_help_s(int *mod_array, int len, char *str)
{
	int i;

	i = -1;
	if (mod_array[8] == 0 || mod_array[4])
	{
		if (mod_array[4] == 0)
		{
			while (mod_array[9]-- > len)
				ft_pputchar(' ');
		}
		while (++i < len)
			ft_pputchar(str[i]);
		if (mod_array[4] != 0)
		{
			while (mod_array[9]-- > len)
				ft_pputchar(' ');
		}
		return ;
	}
	while (mod_array[9]-- > len)
		ft_pputchar('0');
	while (++i < len)
		ft_pputchar(str[i]);
}

void		ft_print_s(int *mod_array, va_list ap)
{
	char	*str;
	int		len;
	int		letters;

	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	letters = ft_pstrlen(str);
	if (mod_array[11])
		mod_array[11] < letters ? (len = mod_array[11]) :\
			(len = letters);
	else
		len = letters;
	ft_help_s(mod_array, len, str);
}

static void	ft_help_ws(int *mod_array, int len, wchar_t *str)
{
	int i;

	i = -1;
	if (mod_array[8] == 0 || mod_array[4])
	{
		if (mod_array[4] == 0)
		{
			while (mod_array[9]-- > len)
				ft_pputchar(' ');
		}
		while (++i < len)
			ft_putwchar(str[i]);
		if (mod_array[4] != 0)
		{
			while (mod_array[9]-- > len)
				ft_pputchar(' ');
		}
		return ;
	}
	while (mod_array[9]-- > len)
		ft_pputchar('0');
	while (++i < len)
		ft_putwchar(str[i]);
}

void		ft_print_ws(int *mod_array, va_list ap)
{
	wchar_t	*str;
	int		len;
	int		letters;

	str = va_arg(ap, wchar_t *);
	if (str == NULL)
		str = L"(null)";
	letters = ft_wstrlen(str);
	if (mod_array[11])
		mod_array[11] < letters ? (len = mod_array[11]) :\
			(len = letters);
	else
		len = letters;
	ft_help_ws(mod_array, len, str);
}

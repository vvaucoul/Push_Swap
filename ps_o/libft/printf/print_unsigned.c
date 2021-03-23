/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksarnyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 16:37:00 by ksarnyts          #+#    #+#             */
/*   Updated: 2017/01/16 11:32:18 by ksarnyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int				ft_count_u(unsigned long long int num)
{
	int letters;

	letters = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num = num / 10;
		letters++;
	}
	return (letters);
}

static void				ft_h(int *m, int len, unsigned long long int n, int f)
{
	int letters;

	letters = ft_count_u(n);
	if (m[10] || m[8] == 0 || m[4])
	{
		if (m[4] == 0)
		{
			while (m[9]-- > len)
				ft_pputchar(' ');
		}
		while (m[11]-- > letters)
			ft_pputchar('0');
		if (!f)
			ft_printulnbr(n);
		if (m[4] != 0)
		{
			while (m[9]-- > len)
				ft_pputchar(' ');
		}
		return ;
	}
	while (m[9]-- > len)
		ft_pputchar('0');
	if (!f)
		ft_printulnbr(n);
}

static long long int	ft_modify(va_list ap, int *mod_array, char c)
{
	unsigned long long int num;

	if (mod_array[2] >= 1)
		num = va_arg(ap, uintmax_t);
	else if (mod_array[0] >= 2)
		num = va_arg(ap, unsigned long long int);
	else if (mod_array[0] == 1 || c == 'U')
		num = va_arg(ap, unsigned long int);
	else if (mod_array[3] >= 1)
		num = va_arg(ap, size_t);
	else if (mod_array[1] >= 2)
		num = (unsigned char)va_arg(ap, int);
	else if (mod_array[1] == 1)
		num = (unsigned short int)va_arg(ap, int);
	else
		num = va_arg(ap, unsigned int);
	return (num);
}

void					ft_print_u(int *mod_array, va_list ap, char c)
{
	unsigned long long int	num;
	int						letters;
	int						len;
	int						flag;

	num = ft_modify(ap, mod_array, c);
	flag = 0;
	letters = ft_count_u(num);
	mod_array[11] > letters ? (len = mod_array[11]) :\
		(len = letters);
	if (mod_array[10] && mod_array[11] == 0 && num == 0)
	{
		flag = 1;
		len = 0;
	}
	ft_h(mod_array, len, num, flag);
}

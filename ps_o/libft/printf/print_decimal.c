/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksarnyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 17:23:23 by ksarnyts          #+#    #+#             */
/*   Updated: 2017/01/16 10:55:34 by ksarnyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int				ft_count_d(long long int num)
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

static void				ft_s(int *mod_array, int len, long long int num, int f)
{
	unsigned long long int	unum;
	int						letters;

	letters = ft_count_d(num);
	if (mod_array[4] == 0)
	{
		while (mod_array[9]-- > len)
			ft_pputchar(' ');
	}
	if (num >= 0 && (mod_array[6] != 0 || mod_array[5] != 0))
		mod_array[5] != 0 ? ft_pputchar('+') : ft_pputchar(' ');
	else if (num < 0)
		ft_pputchar('-');
	while (mod_array[11]-- > letters)
		ft_pputchar('0');
	num < 0 ? (unum = (long long)num * (-1)) :\
		(unum = (long long)num);
	if (!f)
		ft_printulnbr(unum);
	if (mod_array[4] != 0)
	{
		while (mod_array[9]-- > len)
			ft_pputchar(' ');
	}
}

static void				ft_z(int *mod_array, int len, long long int num, int f)
{
	unsigned long long int unum;

	if (num >= 0 && (mod_array[6] != 0 || mod_array[5] != 0))
		mod_array[5] != 0 ? ft_pputchar('+') : ft_pputchar(' ');
	else if (num < 0)
		ft_pputchar('-');
	while (mod_array[9]-- > len)
		ft_pputchar('0');
	num < 0 ? (unum = (long long)num * (-1)) :\
		(unum = (long long)num);
	if (!f)
		ft_printulnbr(unum);
}

static long long int	ft_modify(va_list ap, int *mod_array, char c)
{
	long long int num;

	if (mod_array[2] >= 1)
		num = va_arg(ap, intmax_t);
	else if (mod_array[0] >= 2)
		num = va_arg(ap, long long int);
	else if (mod_array[0] == 1 || c == 'D')
		num = va_arg(ap, long int);
	else if (mod_array[3] >= 1)
		num = va_arg(ap, size_t);
	else if (mod_array[1] >= 2)
		num = (signed char)va_arg(ap, int);
	else if (mod_array[1] == 1)
		num = (short int)va_arg(ap, int);
	else
		num = va_arg(ap, int);
	return (num);
}

void					ft_print_d(int *mod_array, va_list ap, char c)
{
	long long int	num;
	int				letters;
	int				len;
	int				flag;

	num = ft_modify(ap, mod_array, c);
	flag = 0;
	letters = ft_count_d(num);
	mod_array[11] > letters ? (len = mod_array[11]) :\
		(len = letters);
	if (mod_array[5] != 0 || mod_array[6] != 0 || num < 0)
		len++;
	if (mod_array[10] && mod_array[11] == 0 && num == 0)
	{
		flag = 1;
		(mod_array[5] || mod_array[6]) ? (len = 1) : \
						(len = 0);
	}
	if (mod_array[10] || mod_array[8] == 0 || mod_array[4])
		ft_s(mod_array, len, num, flag);
	else
		ft_z(mod_array, len, num, flag);
}

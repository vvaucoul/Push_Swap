/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksarnyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 13:04:43 by ksarnyts          #+#    #+#             */
/*   Updated: 2017/02/13 13:28:38 by ksarnyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int				ft_count_h(unsigned long long int num)
{
	int letters;

	letters = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num = num / 16;
		letters++;
	}
	return (letters);
}

static void				ft_x(int *m, int len, unsigned long long int num, int f)
{
	int letters;

	letters = ft_count_h(num);
	if (m[10] || m[8] == 0 || m[4])
	{
		while (!m[4] && m[9]-- > len)
			ft_pputchar(' ');
		while (m[11]-- > letters)
			ft_pputchar('0');
		if ((!f && m[7] && num != 0) || (f && len == 2))
			ft_pputstr("0x");
		if (!f)
			ft_printulhex(num, 'x');
		while (m[4] && m[9]-- > len)
			ft_pputchar(' ');
		return ;
	}
	if ((!f && m[7] && num != 0) || (f && len == 2))
		ft_pputstr("0x");
	while (m[9]-- > len)
		ft_pputchar('0');
	if (!f)
		ft_printulhex(num, 'x');
}

static void				ft_xx(int *m, int len, unsigned long long int n, int f)
{
	int letters;

	letters = ft_count_h(n);
	if (m[10] || m[8] == 0 || m[4])
	{
		while (!m[4] && m[9]-- > len)
			ft_pputchar(' ');
		while (m[11]-- > letters)
			ft_pputchar('0');
		if (!f && m[7] && n != 0)
			ft_pputstr("0X");
		if (!f)
			ft_printulhex(n, 'X');
		while (m[4] && m[9]-- > len)
			ft_pputchar(' ');
		return ;
	}
	if (!f && m[7] && n != 0)
		ft_pputstr("0X");
	while (m[9]-- > len)
		ft_pputchar('0');
	if (!f)
		ft_printulhex(n, 'X');
}

static long long int	ft_modify(va_list ap, int *mod_array, char c)
{
	unsigned long long int num;

	if (mod_array[2] >= 1)
		num = va_arg(ap, uintmax_t);
	else if (mod_array[0] >= 2)
		num = va_arg(ap, unsigned long long int);
	else if (mod_array[0] == 1 || c == 'p')
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

void					ft_print_h(int *m, va_list ap, char c)
{
	unsigned long long int	num;
	int						letters;
	int						len;
	int						flag;

	num = ft_modify(ap, m, c);
	flag = 0;
	letters = ft_count_h(num);
	m[11] > letters ? (len = m[11]) :\
		(len = letters);
	if (m[7] || c == 'p')
		len += 2;
	if (m[10] && m[11] == 0 && num == 0)
	{
		flag = 1;
		(c == 'p') ? (len = 2)\
			: (len = 0);
	}
	if (c == 'p')
		m[7]++;
	(c == 'X') ? ft_xx(m, len, num, flag) : ft_x(m, len, num, flag);
}

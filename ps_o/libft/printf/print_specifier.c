/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksarnyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 17:35:02 by ksarnyts          #+#    #+#             */
/*   Updated: 2017/01/16 14:41:14 by ksarnyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_just_spec_help(const char c, va_list ap)
{
	char	*str1;
	wchar_t	*str2;

	if (c == 'c')
		ft_pputchar((char)va_arg(ap, int));
	else if (c == 's')
	{
		str1 = va_arg(ap, char *);
		(str1 == NULL) ? ft_pputstr("(null)") : ft_pputstr(str1);
	}
	else if (c == 'p')
	{
		ft_pputstr("0x");
		ft_printaddr(va_arg(ap, unsigned long int));
	}
	else if (c == 'C')
		ft_putwchar(va_arg(ap, wchar_t));
	else if (c == 'S')
	{
		str2 = va_arg(ap, wchar_t *);
		(str2 == NULL) ? ft_pputstr("(null)") : ft_putwstr(str2);
	}
	else if (c == 'D')
		ft_printlnbr(va_arg(ap, long int));
}

static void	ft_print_just_spec(const char c, va_list ap)
{
	if (c == 'D' || c == 'c' || c == 'C' || c == 's' ||\
			c == 'S' || c == 'p')
		ft_print_just_spec_help(c, ap);
	else if (c == 'd' || c == 'i')
		ft_pputnbr(va_arg(ap, int));
	else if (c == 'o')
		ft_printoct(va_arg(ap, int));
	else if (c == 'O')
		ft_printloct(va_arg(ap, long int));
	else if (c == 'u')
		ft_printunbr(va_arg(ap, unsigned int));
	else if (c == 'U')
		ft_printulnbr(va_arg(ap, unsigned long int));
	else if (c == 'x' || c == 'X')
		ft_printhex(va_arg(ap, int), c);
}

static int	ft_check_array(int *mod_array)
{
	int i;

	i = 0;
	while (i < 12)
	{
		if (mod_array[i] != 0)
			return (1);
		i++;
	}
	return (0);
}

static void	ft_print_mod_specifier(int *mod_array, char c, va_list ap)
{
	if (c == 'd' || c == 'i' || c == 'D')
		ft_print_d(mod_array, ap, c);
	else if (c == 'u' || c == 'U')
		ft_print_u(mod_array, ap, c);
	else if (c == 'o' || c == 'O')
		ft_print_o(mod_array, ap, c);
	else if (c == 'x' || c == 'X' || c == 'p')
		ft_print_h(mod_array, ap, c);
	else if (c == 's' && !mod_array[0])
		ft_print_s(mod_array, ap);
	else if ((c == 'S') || (c == 's' && mod_array[0]))
		ft_print_ws(mod_array, ap);
	else if (c == 'c' && !mod_array[0])
		ft_print_c(mod_array, ap);
	else if ((c == 'C') || (c == 'c' && mod_array[0]))
		ft_print_wc(mod_array, ap);
}

int			ft_print_specifier(const char *format, int *i, va_list ap)
{
	int mod_array[12];
	int check_array;

	if (ft_is_specifier(format[*i]))
	{
		ft_print_just_spec(format[*i], ap);
		return (1);
	}
	ft_create_array(mod_array, format, i);
	check_array = ft_check_array(mod_array);
	if (!check_array || !ft_is_specifier(format[*i]))
	{
		if (!format[*i])
			return (0);
		if (!check_array)
		{
			ft_pputchar(format[*i]);
			return (1);
		}
		ft_print_let(mod_array, format[*i]);
		return (1);
	}
	ft_print_mod_specifier(mod_array, format[*i], ap);
	return (1);
}

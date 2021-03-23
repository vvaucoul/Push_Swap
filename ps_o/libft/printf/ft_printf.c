/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksarnyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:13:29 by ksarnyts          #+#    #+#             */
/*   Updated: 2017/01/15 19:08:42 by ksarnyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int		i;
	va_list	ap;

	i = 0;
	g_chars = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (ft_print_specifier(format, &i, ap) == 0)
			{
				va_end(ap);
				return (g_chars);
			}
			i++;
		}
		else
			ft_pputchar(format[i++]);
	}
	va_end(ap);
	return (g_chars);
}

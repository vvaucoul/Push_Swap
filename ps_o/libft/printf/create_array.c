/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksarnyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 17:38:35 by ksarnyts          #+#    #+#             */
/*   Updated: 2017/02/13 13:44:43 by ksarnyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_is_specifier(char c)
{
	if (c == 'd' || c == 'D' || c == 'i' || c == 'c' || c == 'C' || c == 's'\
			|| c == 'S' || c == 'p' || c == 'o' || c == 'O' || c == 'u'\
			|| c == 'U' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

int			ft_is_flag(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0')
		return (1);
	return (0);
}

int			ft_is_modifier(char c)
{
	if (c == 'l' || c == 'h' || c == 'j' || c == 'z')
		return (1);
	return (0);
}

static void	ft_create_mod_array_help(int *mod_array, const char *format, int *i)
{
	if (format[*i] == 'l')
		mod_array[0]++;
	if (format[*i] == 'h')
		mod_array[1]++;
	if (format[*i] == 'j')
		mod_array[2]++;
	if (format[*i] == 'z')
		mod_array[3]++;
	if (format[*i] == '.')
	{
		mod_array[10]++;
		mod_array[11] = 0;
	}
	if (ft_pisdigit(format[*i]))
	{
		if (format[*i - 1] == '.')
			mod_array[11] = ft_patoi(&(format[*i]));
		else
			mod_array[9] = ft_patoi(&(format[*i]));
		while (ft_pisdigit(format[*i]))
			(*i)++;
		(*i)--;
	}
}

int			*ft_create_array(int *mod_array, const char *format, int *i)
{
	int j;

	j = 0;
	while (j < 12)
		mod_array[j++] = 0;
	while (ft_is_modifier(format[*i]) || ft_is_flag(format[*i]) ||\
			ft_pisdigit(format[*i]) || format[*i] == '.')
	{
		if (format[*i] == '-')
			mod_array[4]++;
		if (format[*i] == '+')
			mod_array[5]++;
		if (format[*i] == ' ')
			mod_array[6]++;
		if (format[*i] == '#')
			mod_array[7]++;
		if (format[*i] == '0' && format[*i - 1] != '.')
			mod_array[8]++;
		if (ft_is_modifier(format[*i]) || ft_pisdigit(format[*i]) ||\
				format[*i] == '.')
			ft_create_mod_array_help(mod_array, format, i);
		(*i)++;
	}
	return (mod_array);
}

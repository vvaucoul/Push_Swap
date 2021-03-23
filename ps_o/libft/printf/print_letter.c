/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_letter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksarnyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 18:52:01 by ksarnyts          #+#    #+#             */
/*   Updated: 2017/01/16 11:18:28 by ksarnyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_let(int *mod_array, char c)
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

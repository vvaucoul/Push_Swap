/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksarnyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 19:18:11 by ksarnyts          #+#    #+#             */
/*   Updated: 2016/11/30 08:38:48 by ksarnyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	symb;
	char			*str;

	str = b;
	i = 0;
	symb = c;
	while (i < len)
	{
		str[i] = symb;
		i++;
	}
	return ((void *)str);
}

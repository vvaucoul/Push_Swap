/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksarnyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 09:06:53 by ksarnyts          #+#    #+#             */
/*   Updated: 2016/11/30 08:41:37 by ksarnyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	unsigned int len;
	unsigned int un;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		un = -1 * n;
		len++;
	}
	else
		un = n;
	while (un)
	{
		un = un / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	unsigned int	nb;
	char			*result;
	int				len;

	len = ft_numlen(n);
	if (n < 0)
		nb = -1 * n;
	else
		nb = n;
	if ((result = (char *)malloc(sizeof(*result) * (len + 1))) == NULL)
		return (NULL);
	if (n < 0 && nb != 0)
		result[0] = '-';
	if (nb == 0)
		result[0] = '0';
	result[len] = '\0';
	while (nb)
	{
		result[--len] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (result);
}

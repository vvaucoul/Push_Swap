/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksarnyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 17:10:34 by ksarnyts          #+#    #+#             */
/*   Updated: 2016/11/30 08:41:52 by ksarnyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int	total;
	int	j;
	int	i;
	int	dst_size;

	i = ft_strlen(dst);
	total = size - ft_strlen(dst) - 1;
	if (total <= 0)
		return (size + ft_strlen(src));
	dst_size = (ft_strlen(dst) + ft_strlen(src));
	j = 0;
	while (src[j] && j < total)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst_size);
}

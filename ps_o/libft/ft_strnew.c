/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksarnyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 09:38:43 by ksarnyts          #+#    #+#             */
/*   Updated: 2016/11/30 08:33:33 by ksarnyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = (char *)malloc(sizeof(*ptr) * (size + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i <= size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

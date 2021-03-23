/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksarnyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:06:23 by ksarnyts          #+#    #+#             */
/*   Updated: 2016/11/30 08:17:30 by ksarnyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;

	i = 0;
	if (!little[0])
		return ((char *)big);
	while (big[i] != '\0')
	{
		j = 0;
		while (big[i] == little[j])
		{
			if (little[j] == '\0')
				return ((char *)(big + i - j));
			i++;
			j++;
		}
		if (little[j] == '\0')
			return ((char *)(big + i - j));
		i = i - j + 1;
	}
	return (0);
}

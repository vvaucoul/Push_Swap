/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksarnyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 10:46:23 by ksarnyts          #+#    #+#             */
/*   Updated: 2016/11/29 17:22:59 by ksarnyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*ptr;
	int		len;

	if (s == NULL)
		return (NULL);
	i = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i--;
	j = 0;
	while ((s[j] == ' ' || s[j] == '\t' || s[j] == '\n') && j < i)
		j++;
	len = i - j + 1;
	if ((ptr = (char *)malloc(sizeof(*ptr) * (len + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < len)
		ptr[i++] = s[j++];
	ptr[i] = '\0';
	return (ptr);
}

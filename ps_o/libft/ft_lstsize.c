/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksarnyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 12:31:21 by ksarnyts          #+#    #+#             */
/*   Updated: 2016/12/03 12:38:20 by ksarnyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *alst)
{
	int	size;

	if (alst == NULL)
		return (0);
	size = 0;
	while (alst)
	{
		alst = alst->next;
		size++;
	}
	return (size);
}

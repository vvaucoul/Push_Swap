/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksarnyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:28:21 by ksarnyts          #+#    #+#             */
/*   Updated: 2016/12/01 10:49:22 by ksarnyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *ptr;

	if (*alst != NULL)
	{
		ptr = *alst;
		while (ptr != NULL)
		{
			ptr = ptr->next;
			(del)((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = ptr;
		}
		*alst = NULL;
	}
}

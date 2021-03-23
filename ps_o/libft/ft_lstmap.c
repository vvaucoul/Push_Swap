/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksarnyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:45:52 by ksarnyts          #+#    #+#             */
/*   Updated: 2016/12/14 18:16:38 by ksarnyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_list;

	if (lst == NULL)
		return (NULL);
	new_list = (f)(lst);
	lst = lst->next;
	new_list->next = ft_lstmap(lst, f);
	return (new_list);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksarnyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:07:01 by ksarnyts          #+#    #+#             */
/*   Updated: 2016/11/30 16:30:51 by ksarnyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *ptr;

	ptr = (t_list *)malloc(sizeof(t_list));
	if (ptr == NULL)
		return (NULL);
	if (content == NULL)
	{
		ptr->content = NULL;
		ptr->content_size = 0;
		ptr->next = NULL;
	}
	else
	{
		ptr->content_size = content_size;
		ptr->content = (void *)malloc(sizeof(content) * content_size);
		if (ptr->content == NULL)
			return (NULL);
		ptr->content = ft_memcpy(ptr->content, content, content_size);
		ptr->next = NULL;
	}
	return (ptr);
}

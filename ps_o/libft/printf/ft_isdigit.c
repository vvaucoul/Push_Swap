/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksarnyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 13:44:15 by ksarnyts          #+#    #+#             */
/*   Updated: 2017/02/13 13:44:29 by ksarnyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_pisdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}
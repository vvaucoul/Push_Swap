/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:09:52 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/20 14:30:04 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/checker.h"

void		reset_static_str(char str[], UINT size)
{
	UINT i;

	i = 0;
	while (i < size)
	{
		str[i] = 0;
		++i;
	}
}

void		join_static_str(char str[], char *add)
{
	int i;
	int j;

	i = 0;
	while (str[i])
		++i;
	j = 0;
	while (add[j])
	{
		str[i] = add[j];
		++i;
		++j;
	}
}

void		gotoxy(int x, int y)
{
	char	location[4096];
	char	*tmp;

	join_static_str(location, (char *)0x1B);
	join_static_str(location, "[");
	tmp = ft_itoa(y);
	join_static_str(location, tmp);
	free(tmp);
	join_static_str(location, ";");
	tmp = ft_itoa(x);
	join_static_str(location, tmp);
	free(tmp);
	join_static_str(location, "f");
	ft_putstr_fd(location, 1);
}

void		clear_screen(void)
{
	ft_putstr_fd("\e[1;1H\e[2J", 1);
}

int			init_term(t_term *term)
{
	struct winsize w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	term->term_x = w.ws_col;
	term->term_y = w.ws_row;
	if (term->term_x < MIN_TERM_X || term->term_y < MIN_TERM_Y)
		return (1);
	return (0);
}

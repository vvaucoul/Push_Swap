/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksarnyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 10:02:51 by ksarnyts          #+#    #+#             */
/*   Updated: 2016/12/23 15:13:35 by ksarnyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_join(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*new_str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new_str = (char *)malloc(sizeof(*new_str) * (ft_strlen(s1) + \
				ft_strlen(s2) + 1));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen(s2))
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	free(s1);
	return (new_str);
}

static int		read_stat(char *stat, char **line)
{
	int i;

	i = 0;
	while (stat[i])
	{
		if (stat[i] == '\n')
		{
			*line = ft_memalloc(i + 1);
			ft_strncpy(*line, stat, i);
			i++;
			ft_strcpy(stat, &stat[i]);
			return (1);
		}
		i++;
	}
	*line = ft_memalloc(i + 1);
	ft_strncpy(*line, stat, i);
	stat[0] = '\0';
	return (0);
}

static void		get_line(char **line, char *str, int i)
{
	char *str_tmp;

	str_tmp = ft_memalloc(i + 1);
	ft_strncpy(str_tmp, str, i);
	*line = ft_join(*line, str_tmp);
	free(str_tmp);
}

static int		read_file(const int fd, char **line, char *str, char *stat)
{
	int	rd;
	int	i;

	while ((rd = read(fd, str, BUFF_SIZE)))
	{
		i = 0;
		while (i < rd)
		{
			if (str[i] == '\n')
			{
				get_line(line, str, i);
				i++;
				while (i < rd)
					*stat++ = str[i++];
				*stat = '\0';
				return (1);
			}
			i++;
		}
		get_line(line, str, i);
	}
	if ((*line)[0] == '\0')
		return (0);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	char		*str;
	static char	stat[BUFF_SIZE];

	if (line == NULL || read(fd, *line, 0) == -1)
		return (-1);
	if (read_stat(stat, line))
		return (1);
	str = ft_memalloc(BUFF_SIZE);
	if (read_file(fd, line, str, stat))
	{
		free(str);
		return (1);
	}
	free(str);
	return (0);
}

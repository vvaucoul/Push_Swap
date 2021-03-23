/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksarnyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:11:59 by ksarnyts          #+#    #+#             */
/*   Updated: 2016/11/30 08:42:38 by ksarnyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(char const *str, char c)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != '\0')
			n++;
		while (str[i] != '\0' && str[i] != c)
			i++;
	}
	return (n);
}

static int	letter_count(char const *word, char c)
{
	int i;

	i = 0;
	while (word[i] != c && word[i] != '\0')
		i++;
	return (i);
}

static char	*ft_wordcpy(char const *str, int letters)
{
	char	*ptr;
	int		i;

	ptr = (char *)malloc(sizeof(*ptr) * (letters + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < letters)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		num;
	char	**split;
	int		letter;

	if (s == NULL)
		return (NULL);
	i = 0;
	num = 0;
	if ((split = (char**)malloc(sizeof(char*) * (ft_words(s, c) + 1))) == NULL)
		return (NULL);
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		letter = letter_count(&s[i], c);
		split[num++] = ft_wordcpy(&s[i], letter);
		i = i + letter;
		while (s[i] == c)
			i++;
	}
	split[num] = 0;
	return (split);
}

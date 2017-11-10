/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:29:34 by xamartin          #+#    #+#             */
/*   Updated: 2017/11/10 17:10:44 by xamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

size_t		ft_count_words(const char *str, char c)
{
	size_t	i;
	size_t	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c)
		{
			word++;
			while (str[i] != c)
				i++;
		}
	}
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		j;
	char	**res;

	if (!(res = (char **)malloc(sizeof(*res) * (ft_count_words(s, c) + 1))))
		return (NULL);
	j = -1;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c )
			res[++j] = ft_strdup(s);
		while (*s != c)
			s++;
	}
	res[ft_count_words(s, c)] = 0;
	return (res);
}

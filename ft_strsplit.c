/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:19:56 by xamartin          #+#    #+#             */
/*   Updated: 2017/11/08 19:47:10 by xamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int			ft_count_word(char const *str, char c)
{
	size_t	i;
	int		word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != c)
		{
			word++;
			while (str[i] != c)
				i++;
		}
		i++;
	}
	return (word);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**tab;

	j = ft_count_word(s, c);
	i = 0;
	k = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * (j + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] != c)
			i++;
		if (s[i] != c)
			tab[k++] = ft_strdup(s);
		while (s[i] != c)
			i++;
	}
	tab[j] = 0;
	return (tab);
}

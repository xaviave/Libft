/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:29:34 by xamartin          #+#    #+#             */
/*   Updated: 2017/11/13 13:49:43 by xamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	size_t		j;
	size_t		i;
	char		**res;

	i = ft_count_words(s, c);
	if (!(s && (res = (char **)malloc(sizeof(*res) * (i + 1)))))
		return (NULL);
	j = 0;
	while (*s && i != 0)
	{
		while (*s == c)
			s++;
		if (*s != c && *s != '\0')
			res[j++] = ft_strdup(s);
		while (*s != c)
			s++;
		i--;
	}
	res[ft_count_words(s, c)] = 0;
	return (res);
}

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
	size_t		k;
	size_t		j;
	size_t		i;
	char		**res;

	if (!(s && c))
		return (NULL);
	i = 0;
	j = 0;
	if (!(ret = ft_memalloc(ft_strlen(s) + 1)))
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			k = 0;
			while (s[i + k] != '\0' && s[i + k] != c)
				k++;
			ret[j++] = ft_strsub(s, i, k);
			i += k;
		}
	}
	ret[j] = 0;
	return (res);
}

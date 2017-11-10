/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:49:50 by xamartin          #+#    #+#             */
/*   Updated: 2017/11/10 12:57:08 by xamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		j;
	size_t		k;
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	k = size;
	while (k-- != 0  && *d != '\0')
		d++;
	j = d - dst;
	k = size - j;
	if (k == 0)
		return (j - ft_strlen(s));
	while (*s != '\0')
	{
		if (k != 1)
		{
			*d++ = *s;
			k--;
		}
		s++;
	}
	*d = '\0';
	return (j + (s - src));
}

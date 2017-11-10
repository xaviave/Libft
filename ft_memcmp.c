/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:26:02 by xamartin          #+#    #+#             */
/*   Updated: 2017/11/10 13:43:40 by xamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int				ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	str1;
	unsigned char	str2;

	while (n--)
	{
		str1 = (unsigned char)s1;
		str2 = (unsigned char)s2;
		if (str1 != str2)
			return (str1 - str2);
		s1++;
		s2++;
	}
	return (0);
}

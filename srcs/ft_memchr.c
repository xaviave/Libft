/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:03:18 by xamartin          #+#    #+#             */
/*   Updated: 2017/11/13 10:14:48 by xamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	if (n != 0)
	{
		while (n-- != 0)
		{
			if (*(const unsigned char *)(s++) == (unsigned char)c)
				return ((void *)(s - 1));
		}
	}
	return (NULL);
}

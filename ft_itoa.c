/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:41:55 by xamartin          #+#    #+#             */
/*   Updated: 2017/11/14 12:18:47 by xamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_is_negative(int *n, int *negative)
{
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
	}
}

char			*ft_itoa(int n)
{
	int			mem;
	int			i;
	int			neg;
	char		*str;

	mem = n;
	i = 2;
	neg = 0;
	ft_is_negative(&n, &neg);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	while (mem /= 10)
		i++;
	i += neg;
	if (!(str = (char*)malloc(sizeof(char) * i)))
		return (NULL);
	str[--i] = '\0';
	while (i--)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}

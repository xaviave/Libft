/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:41:55 by xamartin          #+#    #+#             */
/*   Updated: 2017/11/10 15:55:31 by xamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

size_t		ft_count(int n, size_t i)
{
	if (n < 0)
	{
		n = -n;
		i++;
	}
	if (n > 9)
		ft_count((n / 10), (i + 1));
	else
		return (i);
	return (0);
}

char		*ft_rec(int n, size_t i, char *str)
{
	if (n < 0)
	{
		str[i] = '-';
		i++;
	}
	if (n > 9)
	{
		ft_rec((n / 10) , (i + 1), str);
		ft_rec((n % 10) , (i + 1), str);
	}
	if (n < 9)
		str[i] = n + 48;
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	size_t	i;

	i = 0;
	i = ft_count(n, i);
	str = ft_strnew(i);
	ft_rec(n, i, str);
	str[i + 1] = '\0';
	return (str);
}

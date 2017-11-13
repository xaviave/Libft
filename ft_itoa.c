/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:41:55 by xamartin          #+#    #+#             */
/*   Updated: 2017/11/13 15:50:46 by xamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	mem;
	char	*str;
	size_t	i;
	int		j;

	i = 0;
	j = n;
	if (n < 0)
	{
		mem = '-';
		j = -j;
		n = -n;
	}
	else
		mem = '+';
	while (j /= 10)
		i++;
	(mem == '-') ? i++ : 0;
	if (!(str = (char *)malloc(sizeof(char) * i)))
		return (NULL);
	str[i--] = '\0';
	while (i--)
	{
		str[i] = (n % 10) + 48;
		n = n / 10;
	}
	(mem == '-') ? str[0] = '-' : 0;
	return (str);
}

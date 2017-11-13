/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:12:05 by xamartin          #+#    #+#             */
/*   Updated: 2017/11/13 10:11:41 by xamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *nptr)
{
	size_t	i;
	char	n;
	size_t	out;

	i = 0;
	out = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		n = nptr[i++];
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		out = out * 10 + nptr[i] - 48;
		i++;
	}
	if (n == '-')
		out = -out;
	return (out);
}

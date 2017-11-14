/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:12:33 by xamartin          #+#    #+#             */
/*   Updated: 2017/11/13 10:13:05 by xamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_bzero(void *s, size_t n)
{
	char	*a;
	size_t	i;

	i = 0;
	a = s;
	while (i < n)
	{
		a[i] = '\0';
		i++;
	}
}

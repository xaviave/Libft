/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:47:13 by xamartin          #+#    #+#             */
/*   Updated: 2017/11/10 16:04:53 by xamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void		ft_strclr(char *s)
{
	while (*s != '\0')
	{
		*s = '\0';
		s++;
	}
}

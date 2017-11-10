/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:46:31 by xamartin          #+#    #+#             */
/*   Updated: 2017/11/08 17:42:22 by xamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void		*ft_memalloc(size_t size)
{
	void	*mem;
	
	if (!(mem = (void *)malloc(sizeof(void) * size)))
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}

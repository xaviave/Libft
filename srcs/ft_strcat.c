/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:16:59 by xamartin          #+#    #+#             */
/*   Updated: 2017/11/13 10:17:43 by xamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcat(char *dst, const char *src)
{
	size_t	i;

	i = ft_strlen(dst);
	ft_strcpy(&dst[i], src);
	return (dst);
}

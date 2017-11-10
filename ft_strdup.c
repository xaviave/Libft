/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:22:38 by xamartin          #+#    #+#             */
/*   Updated: 2017/11/09 14:17:11 by xamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

char		*ft_strdup(const char *s)
{
	size_t	i;
	char	*out;

	i = ft_strlen(s);
	if (!(out = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		out[i] = s[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}

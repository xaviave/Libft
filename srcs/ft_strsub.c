/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:35:54 by xamartin          #+#    #+#             */
/*   Updated: 2017/11/14 09:32:19 by xamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	j = 0;
	i = (size_t)start;
	if (s)
	{
		if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (j < len && s[i] != '\0')
		{
			str[j] = s[i];
			i++;
			j++;
		}
		str[j] = '\0';
		return (str);
	}
	return (NULL);
}

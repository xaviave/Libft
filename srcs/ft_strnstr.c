/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:01:55 by xamartin          #+#    #+#             */
/*   Updated: 2017/11/14 09:37:11 by xamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = ft_strlen(haystack);
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	if (k == 0)
		return (NULL);
	while (haystack[i] && i < len)
	{
		while (haystack[i + j] == needle[j] && (i + j) < len)
		{
			if (!needle[j + 1])
				return ((char *)&haystack[i]);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}

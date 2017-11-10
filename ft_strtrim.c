/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:24:59 by xamartin          #+#    #+#             */
/*   Updated: 2017/11/08 20:02:19 by xamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int			ft_debut(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] == '\n' || s[i] == '\t' || s[i] == ' ')
		i++;
	return (i);
}

int			ft_fin(const char *s)
{
	size_t	i;

	i = ft_strlen(s);
	while (s[i] == '\n' || s[i] == '\t' || s[i] == ' ')
		i--;
	return (i);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;

	i = ft_strlen(s);
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = ft_debut(s);
	while (s[i] != '\0' && i < (size_t)ft_fin(s))
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}

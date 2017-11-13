/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 09:32:19 by xamartin          #+#    #+#             */
/*   Updated: 2017/11/13 11:15:20 by xamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
	char    *tab;
	size_t	i;

	if (s1 && s2)
	{
		i = ft_strlen(s1) + ft_strlen(s2);
		if ((tab = ft_strnew(i)) == NULL)
			return (NULL);
		ft_strcpy(tab, s1);
		ft_strcat(tab, s2);
		return (tab);
	}
	return (NULL);
}

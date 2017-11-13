/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:39:16 by xamartin          #+#    #+#             */
/*   Updated: 2017/11/13 13:40:31 by xamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t          ft_count_words(const char *str, char c)
{
	size_t      i;
	size_t      word;

	i = 0;
	word = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c)
		{
			word++;
			while (str[i] != c)
				i++;
		}
	}
	return (word);
}

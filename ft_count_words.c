/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_count_words.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 16:30:52 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 16:30:52 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_count_words(const char *str, int c)
{
	size_t		i;
	size_t		word;

	i = 0;
	word = 0;
	if (str)
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i] != c && str[i] != '\0')
		{
			word++;
			while (str[i] != c && str[i] != '\0')
				i++;
		}
	}
	return (word);
}

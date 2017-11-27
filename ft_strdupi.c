/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdupi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 16:30:55 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 16:30:55 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdupi(const char *s, int c)
{
	size_t	i;
	char	*out;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
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

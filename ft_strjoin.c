/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 16:30:56 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 16:30:56 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;
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

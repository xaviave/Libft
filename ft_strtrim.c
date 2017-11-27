/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 16:31:17 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 16:31:17 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s)
		return (NULL);
	while ((s[i] == '\t' || s[i] == '\n' || s[i] == ' ') && s[i])
		i++;
	j = ft_strlen(s) - 1;
	while ((s[j] == '\t' || s[j] == '\n' || s[j] == ' ') && s[j])
		j--;
	if (s[i] == '\0')
	{
		str = ft_strnew(1);
		return (str);
	}
	j = j - i + 1;
	str = ft_strsub(s, i, j);
	return (str);
}

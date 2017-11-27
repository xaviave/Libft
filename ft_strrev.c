/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrev.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 16:31:17 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 16:31:17 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(char *str)
{
	size_t	i;
	size_t	a;
	int		c;

	i = 0;
	a = 0;
	while (str[i])
		i++;
	i -= 1;
	while (i > a)
	{
		c = str[i];
		str[i] = str[a];
		str[a] = c;
		i--;
		a++;
	}
	return (str);
}

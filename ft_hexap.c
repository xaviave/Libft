/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_hexap.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 16:26:04 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/03 18:06:23 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_hexap(char *format, va_list ap)
{
	size_t	i;
	size_t	j;
	t_opt	option;

	i = 1;
	j = parseall(format, &option, 6);
	if (option.star)
		option.accurancy = (int)va_arg(ap, int);
	i = basenumber1((unsigned long)va_arg(ap, int), option, 16, 0);
	return (i);
}

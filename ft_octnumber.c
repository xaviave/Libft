/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_octnumber.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/05 16:38:08 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/03 18:06:52 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_octnumber(char *format, va_list ap)
{
	size_t		i;
	size_t		j;
	t_opt		option;

	i = 1;
	j = parseall(format, &option, 4);
	if (option.star)
		option.accurancy = (int)va_arg(ap, int);
	if (option.l == 1 || option.l == 2)
		i = basenumber1((unsigned long)va_arg(ap, long), option, 8, 0);
	else if (option.h == 1)
		i = basenumber1((unsigned short)va_arg(ap, int), option, 8, 0);
	else if (option.h == 2)
		i = basenumber1((unsigned char)va_arg(ap, int), option, 8, 0);
	else if (option.j == 1)
		i = basenumber1((uintmax_t)va_arg(ap, long), option, 8, 0);
	else if (option.z == 1)
		i = basenumber1((size_t)va_arg(ap, long), option, 8, 0);
	else
		i = basenumber1((unsigned int)va_arg(ap, int), option, 8, 0);
	return (i);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_unsnumber.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 16:25:08 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/03 18:06:11 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_unsnumber(char *format, va_list ap)
{
	size_t	i;
	t_opt	option;

	i = parseall(format, &option, 3);
	if (option.star)
		option.accurancy = (int)va_arg(ap, int);
	if (option.l == 1 || option.l == 2 || option.hashtag ||
			format[ft_strlen(format) - 1] == 'U')
		i = basenumber1((unsigned long)va_arg(ap, unsigned long),
				option, 10, 0);
	else if (option.h == 1)
		i = basenumber1((unsigned short)va_arg(ap, unsigned long),
				option, 10, 0);
	else if (option.h == 2)
		i = basenumber1((unsigned char)va_arg(ap, unsigned long),
				option, 10, 0);
	else if (option.j == 1)
		i = basenumber1((uintmax_t)va_arg(ap, unsigned long), option, 10, 0);
	else if (option.z == 1)
		i = basenumber1((size_t)va_arg(ap, long), option, 10, 0);
	else
		i = basenumber1((unsigned int)va_arg(ap, unsigned long),
				option, 10, 0);
	return (i);
}

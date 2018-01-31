/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_luitoa_base.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 12:48:44 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 12:49:47 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char				*ft_luitoa_base(unsigned long n, int base)
{
	static char		list[] = "0123456789abcdef";
	unsigned long	temp;
	int				digits;
	char			*output;

	temp = n;
	digits = 1;
	while (temp /= base)
		digits++;
	output = ft_strnew(digits);
	temp = n;
	while (digits--)
	{
		output[digits] = list[temp % base];
		temp /= base;
	}
	return (output);
}

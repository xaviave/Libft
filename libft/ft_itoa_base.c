/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_luitoa_base.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 12:48:44 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/03 18:09:12 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char				*ft_itoa_base(long n, int base)
{
	static char		list[] = "0123456789abcdef";
	unsigned long	temp;
	char			digits;
	char			neg;
	char			*output;

	neg = (n < 0 && base == 10 ? 1 : 0);
	temp = n < 0 ? -n : n;
	digits = 1;
	while (temp /= base)
		digits++;
	output = ft_strnew(digits + neg);
	temp = n < 0 ? -n : n;
	while (digits--)
	{
		output[digits + neg] = list[temp % base];
		temp /= base;
	}
	output[0] = neg ? '-' : output[0];
	return (output);
}

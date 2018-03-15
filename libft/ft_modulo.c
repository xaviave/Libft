/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_modulo.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/11 09:09:40 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/03 18:06:35 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_modulo(char *format, va_list ap)
{
	size_t	i;
	t_opt	option;
	char	*enter;

	i = 0;
	parseall(format, &option, 7);
	if (option.star)
		option.accurancy = (int)va_arg(ap, int);
	enter = ft_strdup("%");
	apoption(&option, &enter, 0);
	if (option.accurancy || (option.accurancy && (option.blank
					&& (option.ok == 1 || !option.ok || option.zero))))
		blank(&enter, &option, 0);
	i = ft_strlen(enter);
	ft_putstr(enter);
	ft_strdel(&enter);
	return (i);
}

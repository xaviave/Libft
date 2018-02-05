/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_string.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 18:23:30 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/03 18:07:04 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t		string(char *str, t_opt option)
{
	size_t	i;
	char	*tmp;

	i = 0;
	if (str)
		tmp = ft_strdup(str);
	else
		tmp = ft_strdup("(null)");
	apoption(&option, &tmp, 0);
	if (option.accurancy || (option.accurancy && (option.blank
					&& (option.ok == 1 || !option.ok || option.zero))))
		blank(&tmp, &option, 0);
	ft_putstr(tmp);
	i = ft_strlen(tmp);
	ft_strdel(&tmp);
	return (i);
}

size_t		string1(wchar_t *wstr, t_opt option)
{
	size_t	i;
	char	*str;

	i = 0;
	str = ft_strdup("");
	apoption(&option, &str, 0);
	if (option.accurancy || (option.accurancy && (option.blank
					&& (option.ok == 1 || !option.ok || option.zero))))
		blank(&str, &option, 0);
	if (wstr)
		i += ft_putwstr(wstr);
	else
	{
		i += 6;
		ft_putstr("(null)");
	}
	ft_strdel(&str);
	return (i);
}

size_t		ft_string(char *format, va_list ap)
{
	size_t	i;
	size_t	j;
	t_opt	option;

	i = 1;
	j = parseall(format, &option, 0);
	if (option.star)
		option.accurancy = (int)va_arg(ap, int);
	if (option.l == 1 || format[ft_strlen(format) - 1] == 'S')
		i = string1((wchar_t *)va_arg(ap, wchar_t *), option);
	else
		i = string((char *)va_arg(ap, char *), option);
	return (i);
}

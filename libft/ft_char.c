/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_char.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 16:28:00 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/03 18:04:05 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static size_t	nochar(t_opt *option, char *str)
{
	option->accurancy -= 1;
	apoption(option, &str, 0);
	if (option->accurancy || (option->accurancy && (option->blank
					&& (option->ok == 1 || !option->ok || option->zero))))
		blank(&str, option, 0);
	ft_putstr(str);
	ft_putchar('\0');
	return (ft_strlen(str) + 1);
}

size_t			affchar(char c, t_opt *option)
{
	size_t		i;
	char		*str;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (0);
	if (c == '\0')
		return (nochar(option, str));
	else
	{
		str[0] = c;
		str[1] = '\0';
		apoption(option, &str, 0);
		if (option->accurancy || (option->accurancy && (option->blank
						&& (option->ok == 1 || !option->ok || option->zero))))
			blank(&str, option, 0);
		ft_putstr(str);
		i = ft_strlen(str);
	}
	ft_strdel(&str);
	return (i);
}

size_t			affchar1(wchar_t c, t_opt *option)
{
	size_t		i;
	char		*str;

	str = "";
	apoption(option, &str, 0);
	if (option->accurancy || (option->accurancy && (option->blank
					&& (option->ok == 1 || !option->ok || option->zero))))
		blank(&str, option, 0);
	ft_putstr(str);
	i = ft_putwchar(c);
	i += ft_strlen(str);
	return (i);
}

size_t			ft_char(char *format, va_list ap)
{
	size_t	i;
	size_t	j;
	t_opt	option;

	i = 1;
	j = parseall(format, &option, 5);
	if (option.star)
		option.accurancy = (int)va_arg(ap, int);
	if (option.l == 1 || format[ft_strlen(format) - 1] == 'C')
		i = affchar1((wchar_t)va_arg(ap, wchar_t), &option);
	else
		i = affchar((char)va_arg(ap, int), &option);
	return (i);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 15:11:40 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/03 18:05:58 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		parse(char *format, va_list ap)
{
	size_t		i;

	i = 1;
	while (format[i])
	{
		if (format[i] == 's' || format[i] == 'S')
			return (ft_string(format, ap));
		if (format[i] == 'o' || format[i] == 'O')
			return (ft_octnumber(format, ap));
		if (format[i] == 'u' || format[i] == 'U')
			return (ft_unsnumber(format, ap));
		if (format[i] == 'x' || format[i] == 'X')
			return (ft_hexnumber(format, ap));
		if (format[i] == 'd' || format[i] == 'D' || format[i] == 'i')
			return (ft_number(format, ap));
		if (format[i] == 'c' || format[i] == 'C')
			return (ft_char(format, ap));
		if (format[i] == 'p')
			return (ft_hexap(format, ap));
		if (format[i] == '%')
			return (ft_modulo(format, ap));
		i++;
	}
	return (0);
}

size_t			count_size(char *str)
{
	size_t		i;

	i = 1;
	while (str[i] && str[i] != 's' && str[i] != 'S' && str[i] != 'o'
			&& str[i] != 'O' && str[i] != 'u' && str[i] != 'U'
			&& str[i] != 'x' && str[i] != 'X' && str[i] != 'd'
			&& str[i] != 'D' && str[i] != 'i' && str[i] != 'c'
			&& str[i] != 'C' && str[i] != 'p' && str[i] != '%')
		i++;
	return (i + 1);
}

static int		dir(char *format, va_list ap)
{
	size_t		i;
	size_t		j;
	size_t		out;
	char		*str;

	i = 0;
	j = 0;
	out = 0;
	if (ft_strcmp(format, "%") == 0)
		return (0);
	while (format[i])
		if (format[i] == '%')
		{
			str = ft_strsub(&format[i], 0, count_size(&format[i]));
			out += parse(str, ap);
			i += count_size(&format[i]);
			ft_strdel(&str);
		}
		else
		{
			ft_putchar(format[i++]);
			j++;
		}
	return (j + out);
}

int				ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	size_t		size;

	va_start(ap, format);
	size = dir((char *)format, ap);
	va_end(ap);
	return (size);
}

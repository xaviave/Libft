/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_number.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 15:40:32 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/03 18:05:36 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t			basenumber(long nu, t_opt *option, int base)
{
	size_t		i;
	long		memnu;
	char		*enter;

	i = 0;
	if (nu < 0 && (option->plus || option->zero || option->min))
	{
		memnu = -nu;
		option->plus = -1;
	}
	else
		memnu = nu;
	if (!nu && option->point == '.')
		enter = ft_strdup("\0");
	else
		enter = ft_itoa_base(memnu, base);
	apoption(option, &enter, nu);
	if (option->accurancy || (option->accurancy && (option->blank
					&& (option->ok == 1 || !option->ok || option->zero))))
		blank(&enter, option, nu);
	ft_putstr(enter);
	i = ft_strlen(enter);
	if (enter)
		free(enter);
	return (i);
}

static void		changep(char **str)
{
	char		*tmp;
	size_t		i;

	i = 0;
	while (ft_strlen(*str) - i > 8)
		i++;
	tmp = *str;
	*str = ft_strsub(*str, i, 8);
	ft_strdel(&tmp);
	if (ft_strcmp(*str, "0") != 0)
		*str = ft_strjoinf2("0x7fff", *str);
	else
	{
		tmp = *str;
		*str = ft_strdup("0x0");
		ft_strdel(&tmp);
	}
}

size_t			basenumber1(unsigned long nu, t_opt option, int base,
		size_t letter)
{
	size_t		i;
	char		*enter;

	i = -1;
	if ((option.ok == 2 || (option.ok == 4 && !option.hashtag))
			&& !nu && option.point == '.')
		enter = ft_strdup("\0");
	else
		enter = ft_luitoa_base(nu, base);
	if (option.ok == 6)
		changep(&enter);
	apoption(&option, &enter, nu);
	if (option.accurancy || (option.accurancy && (option.blank
					&& (option.ok == 1 || !option.ok || option.zero))))
		blank(&enter, &option, nu);
	if (letter == 1)
		while (enter[++i])
			enter[i] = ft_toupper(enter[i]);
	ft_putstr(enter);
	i = ft_strlen(enter);
	if (enter)
		free(enter);
	return (i);
}

size_t			ft_number(char *format, va_list ap)
{
	size_t		i;
	size_t		j;
	t_opt		option;

	i = 1;
	j = parseall(format, &option, 1);
	if (option.star)
		option.accurancy = (int)va_arg(ap, int);
	if (option.l == 1 || option.l == 2)
		i = basenumber((long)va_arg(ap, long), &option, 10);
	else if (option.h == 1)
		i = basenumber((short)va_arg(ap, long), &option, 10);
	else if (option.h == 2)
		i = basenumber((char)va_arg(ap, long), &option, 10);
	else if (option.j == 1)
		i = basenumber((intmax_t)va_arg(ap, long), &option, 10);
	else if (option.z == 1)
		i = basenumber((ssize_t)va_arg(ap, long), &option, 10);
	else
		i = basenumber((int)va_arg(ap, int), &option, 10);
	return (i);
}

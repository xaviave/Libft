/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/14 12:10:53 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/03 18:05:16 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void		initstruct(t_opt *option, int ok)
{
	option->l = 0;
	option->h = 0;
	option->j = 0;
	option->z = 0;
	option->hashtag = 0;
	option->zero = 0;
	option->less = 0;
	option->plus = 0;
	option->blank = 0;
	option->accurancy = 0;
	option->min = 0;
	option->star = 0;
	option->ok = ok;
	option->point = 'p';
	option->damn = 0;
}

size_t			parseac(char *format, size_t i, int *t)
{
	*t = format[i] - 48;
	i++;
	while (format[i] >= '0' && format[i] <= '9')
	{
		*t = *t * 10 + format[i] - 48;
		i++;
	}
	return (i - 1);
}

size_t			parseall1(char *format, size_t i, t_opt *option)
{
	if (format[i] == '#')
		option->hashtag++;
	else if (format[i] == '0')
		option->zero++;
	else if (format[i] == '-')
		option->less++;
	else if (format[i] == '+')
		option->plus++;
	else if (format[i] == ' ')
		option->blank++;
	else if (format[i] > '0' && format[i] <= '9')
		i = parseac(format, i, &option->accurancy);
	else if (format[i] == '*')
		option->star++;
	else if (format[i] == '.')
	{
		option->point = '.';
		if (format[i + 1] >= '0' && format[i + 1] <= '9')
			i = parseac(format, i + 1, &option->min);
	}
	return (i);
}

size_t			parseall2(char *format, size_t i, t_opt *option)
{
	size_t		j;

	j = 0;
	if ((format[i] == 'l' || format[i] == 'h' || format[i] == 'j'
				|| format[i] == 'z') && format[i] != '\0')
	{
		while (j < 2 && format[i])
		{
			if (format[i] == 'l')
				option->l++;
			else if (format[i] == 'h')
				option->h++;
			else if (format[i] == 'j')
				option->j++;
			else if (format[i] == 'z')
				option->z++;
			i++;
			j++;
		}
	}
	return (i);
}

int				parseall(char *format, t_opt *option, int ok)
{
	size_t		i;

	i = 1;
	initstruct(option, ok);
	option->letter = format[ft_strlen(format) - 1] == 'X' ? 1 : 0;
	while (i < ft_strlen(format) && format[i])
	{
		i = parseall1(format, i, option);
		i = parseall2(format, i, option);
		i++;
	}
	return (i);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   option.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/15 14:28:20 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/03 18:05:06 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void				zero(char **str, int nu)
{
	char			*tmp;
	char			*tmp1;
	size_t			i;

	i = 0;
	tmp = (char *)ft_memalloc(sizeof(char) * (nu - ft_strlen(*str) + 1) + 1);
	if (nu - (int)ft_strlen(*str) < 0)
		return ;
	while (i < (size_t)nu - ft_strlen(*str))
	{
		tmp[i] = '0';
		i++;
	}
	tmp1 = *str;
	*str = ft_strjoin(tmp, *str);
	ft_strdel(&tmp);
	ft_strdel(&tmp1);
}

static void			blank1(char **str, t_opt *option, char *test)
{
	char			*tmp;
	size_t			i;

	i = 0;
	tmp = (char *)ft_memalloc(sizeof(char) * (option->accurancy
				- ft_strlen(*str) + 1) + 1);
	while (i < (size_t)option->accurancy - ft_strlen(*str))
		tmp[i++] = ' ';
	if (str)
	{
		test = *str;
		if (option->less)
			*str = ft_strjoin(*str, tmp);
		else
			*str = ft_strjoin(tmp, *str);
		free(test);
	}
	else
		*str = ft_strdup(tmp);
	ft_strdel(&tmp);
}

void				blank(char **str, t_opt *option, long nu)
{
	char			*test;

	if (option->blank && (!option->accurancy || (option->accurancy
					< (int)ft_strlen(*str))) && ((option->ok == 1
					&& nu > 0) || !option->ok))
	{
		test = *str;
		*str = ft_strjoin(" ", *str);
		free(test);
	}
	if (option->accurancy - (int)ft_strlen(*str) < 0)
		return ;
	blank1(str, option, test);
}

void				plus(char **str, long nu)
{
	char	*tmp;

	tmp = *str;
	if (nu >= 0)
		*str = ft_strjoin("+", *str);
	else
		*str = ft_strjoin("-", *str);
	free(tmp);
}

char				*hashtag(char **str, t_opt *option)
{
	char *tmp;

	if (option->ok == 2)
	{
		if (ft_strcmp(*str, "7fffffffffffffff") == 0)
			return (ft_strdup("0x7fffffffffffffff"));
		tmp = ft_strjoin("0x", *str);
		ft_strdel(str);
		return (tmp);
	}
	else if (option->ok == 4)
	{
		tmp = ft_strjoin("0", *str);
		ft_strdel(str);
		return (tmp);
	}
	return (NULL);
}

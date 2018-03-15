/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   option2.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 16:57:01 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/03 18:05:11 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void	apoption1(t_opt *option, char **str, long nu)
{
	if (option->accurancy && option->zero && !option->less && !option->min
			&& (((option->ok > 1 && option->ok <= 4) && !option->blank)
				|| (option->ok == 1 && (option->blank || !option->blank))))
	{
		if (option->accurancy && option->zero && !option->less && !option->min
				&& option->ok == 1 && option->blank)
			option->damn = 1;
		if (option->hashtag == 1)
			option->accurancy = option->accurancy - 2;
		if (option->damn)
			zero(str, option->accurancy - 1);
		else
			zero(str, option->accurancy);
	}
	if (option->hashtag && nu)
		*str = hashtag(str, option);
	if (option->plus && option->ok == 1)
		plus(str, nu);
}

void		apoption(t_opt *option, char **str, long nu)
{
	if (option->blank && !option->accurancy && !option->zero
			&& !option->less && option->plus < 1)
		option->accurancy = 1;
	if (((option->accurancy > 1 && option->zero && option->plus > 0)
				|| ((!option->zero || !option->less) && option->plus == -1))
			&& option->ok == 1)
		option->accurancy -= 1;
	if (!option->ok && option->min)
		*str = ft_strsub(*str, 0, option->min);
	if ((option->ok == 4 || option->ok == 1 || option->ok == 3)
			&& option->min > 0)
		zero(str, option->min);
	apoption1(option, str, nu);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:55:09 by xamartin          #+#    #+#             */
/*   Updated: 2017/11/14 19:06:24 by xamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmplst;
	t_list	*tmplst2;

	tmplst2 = *alst;
	while (tmplst2)
	{
		tmplst = tmplst2->next;
		del(tmplst2->content, tmplst2->content_size);
		free(tmplst2);
		tmplst2 = tmplst;
	}
	*alst = NULL;
}

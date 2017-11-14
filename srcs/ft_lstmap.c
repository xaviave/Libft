/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 20:25:27 by xamartin          #+#    #+#             */
/*   Updated: 2017/11/14 21:52:01 by xamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*tmplst;
	t_list	*tmplst2;

	if (!lst || !f)
		return (NULL);
	tmplst2 = f(lst);
	if ((newlst = ft_lstnew(tmplst2->content, tmplst2->content_size)))
	{
		tmplst = newlst;
		lst = lst->next;
		while (lst)
		{
			tmplst2 = f(lst);
			if (!(tmplst->next = ft_lstnew(tmplst2->content, tmplst2->content_size)))
				return (NULL);
			tmplst = tmplst->next;
			lst = lst->next;
		}
	}
	return (newlst);
}

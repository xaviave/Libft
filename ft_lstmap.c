/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 16:30:53 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 16:30:53 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*tmplst;
	t_list	*tmplst2;

	if (!lst || !f || !(tmplst2 = f(lst)))
		return (NULL);
	if ((newlst = ft_lstnew(tmplst2->content, tmplst2->content_size)))
	{
		tmplst = newlst;
		lst = lst->next;
		while (lst)
		{
			tmplst2 = f(lst);
			if (!(tmplst->next =
						ft_lstnew(tmplst2->content, tmplst2->content_size)))
				return (NULL);
			tmplst = tmplst->next;
			lst = lst->next;
		}
	}
	return (newlst);
}

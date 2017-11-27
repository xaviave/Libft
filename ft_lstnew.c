/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 16:30:53 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 16:32:53 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlst;

	if (!(newlst = ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (content)
		newlst->content = ft_memalloc((size_t)(sizeof(content) * content_size));
	else
		content = NULL;
	if (newlst->content)
		ft_memcpy(newlst->content, content, content_size);
	if (content)
		newlst->content_size = content_size;
	else
		content_size = 0;
	newlst->next = NULL;
	return (newlst);
}

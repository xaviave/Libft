/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:27:20 by xamartin          #+#    #+#             */
/*   Updated: 2017/11/14 19:17:21 by xamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlst;

	if (!(newlst = ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (content)
		newlst->content = ft_memalloc(content_size);
	else
		content = NULL;
	ft_memcpy(newlst->content, content, content_size);
	content_size = 0;
	newlst->content_size = content_size;
	newlst->next = NULL;
	return (newlst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:33:37 by alvjimen          #+#    #+#             */
/*   Updated: 2022/06/27 20:07:58 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

static t_list	*new_node(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	void	*content;

	if (!lst)
		return (NULL);
	content = f(lst->content);
	if (!content)
		return (NULL);
	node = ft_lstnew(content);
	if (!node)
	{
		del(content);
		return (NULL);
	}
	return (node);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*node;

	new_list = NULL;
	while (lst)
	{
		node = new_node(lst, f, del);
		if (!node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, node);
		lst = lst->next;
	}
	return (new_list);
}

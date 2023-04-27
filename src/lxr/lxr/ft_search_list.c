/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:09:40 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/21 19:58:23 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

t_list	*ft_search_list(t_list *lst, int (*f)(void *))
{
	t_list	*node;
	t_tkn	*tokens;

	if (!lst)
		return (NULL);
	node = lst;
	while (lst)
	{
		if (f(lst->content) == SUCCESS)
		{
			tokens = lst->content;
			if (!tokens)
				continue ;
			tokens->found = 1;
			break ;
		}
		lst = lst->next;
	}
	return (lst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:17:03 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/24 14:10:35 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

/*
	lst == equal to first part.
	delim == equal to second part.
*/
static int	ft_split_first(t_list *lst, t_list *delim)
{
	if (!lst)
		return (FAILURE);
	if (lst == delim)
		return (SUCCESS);
	while (lst && lst->next != delim)
		lst = lst->next;
	if (!lst)
		return (FAILURE);
	lst->next = NULL;
	return (SUCCESS);
}

static t_list	*ft_get_last(t_list *lst, int (*f)(void *))
{
	t_list	*backup;
	t_tkn	*tkns;

	backup = NULL;
	while (lst)
	{
		lst = ft_search_list(lst, (*f));
		if (!lst)
			break ;
		if (backup)
		{
			tkns = backup->content;
			tkns->found = 0;
		}
		backup = lst;
		lst = lst->next;
	}
	return (backup);
}

t_list	*ft_split_list_first(t_list **lst, int (*f)(void *))
{
	t_list	*second;

	if (!lst || !*lst)
		return (NULL);
	second = ft_search_list(*lst, (*f));
	if (!second)
		return (NULL);
	if (ft_split_first(*lst, second))
		return (NULL);
	return (second);
}

t_list	*ft_split_list(t_list **lst, int (*f)(void *))
{
	t_list	*second;

	if (!lst || !*lst)
		return (NULL);
	second = ft_get_last(*lst, (*f));
	if (!second)
		return (NULL);
	if (ft_split_first(*lst, second))
		return (NULL);
	return (second);
}

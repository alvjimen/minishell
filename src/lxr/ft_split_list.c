/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:17:03 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/16 21:02:48 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

int	ft_split_first(t_list *lst, t_list *delim)
{
	if (!lst)
		return (1);
	while (lst && lst->next != delim)
		lst = lst->next;
	if (!lst)
		return (1);
	lst->next = NULL;
	return (0);
}

t_list	*ft_split_list(t_list *lst)
{
	t_list	*second;

	second = ft_search_list(lst, AND_IF | OR_IF);
	if (!second)
		return (NULL);
	if (ft_split_first(lst, second))
		return (NULL);
	return (second)
}

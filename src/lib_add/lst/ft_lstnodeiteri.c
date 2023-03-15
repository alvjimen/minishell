/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnodeiteri.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:23:06 by alvjimen          #+#    #+#             */
/*   Updated: 2023/01/30 17:17:13 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lst.h"

/* ! Doesn't destroy the node or the list as function pls?  */
void	ft_lstnodeiteri(t_list *node, void (*n)(t_list *node))
{
	t_list	*next;

	if (!n)
		return ;
	while (node)
	{
		next = node->next;
		n(node);
		node = next;
	}
}

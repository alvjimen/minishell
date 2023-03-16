/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:09:40 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/16 20:58:33 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

t_list	*ft_search_list(t_list *lst, f(void *))
{
	t_list	*node;
	t_tkn	*tokens;

	if (!lst)
		return (NULL);
	node = lst;
	while (lst)
	{
		if (!f(lst->content))
			break
		lst = lst->next;
	}
	return (lst);
}

int	ft_operators_interpipelines(void *ptr)
{
	t_tkn	*tokens;

	tokens = ptr;
	if (tokens && tokens->operators & (OR_IF | AND_IF))
		return (0);
	return (1);
}

int	ft_operators_intercmd(void *ptr)
{
	t_tkn	*tokens;

	tokens = ptr;
	if (tokens && tokens->operators & PIPE)
		return (0);
	return (1);
}

int	ft_operators_intracmd(void *ptr)
{
	t_tkn	*tokens;

	tokens = ptr;
	if (tokens && tokens->operators & (DGREATER | GREATER | LOWER | DLOWER))
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:09:40 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/18 19:26:17 by alvjimen         ###   ########.fr       */
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
		if (!f(lst->content))
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

int	ft_operators_interpipelines(void *ptr)
{
	t_tkn	*tokens;

	if (!ptr)
		return (1)
	tokens = ptr;
	if (tokens && !tokens->found && tokens->operators & (OR_IF | AND_IF))
		return (0);
	return (1);
}

int	ft_operators_intercmd(void *ptr)
{
	t_tkn	*tokens;

	if (!ptr)
		return (1)
	tokens = ptr;
	if (tokens && !tokens->found && tokens->operators & PIPE)
		return (0);
	return (1);
}

int	ft_operators_intracmd(void *ptr)
{
	t_tkn	*tokens;

	if (!ptr)
		return (1)
	tokens = ptr;
	if (tokens && !tokens->found
		&& tokens->operators & (DGREATER | GREATER | LOWER | DLOWER))
		return (0);
	return (1);
}

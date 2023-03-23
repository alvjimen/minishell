/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:09:40 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/22 19:08:51 by alvjimen         ###   ########.fr       */
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
		return (FAILURE);
	tokens = ptr;
	if (tokens && !tokens->found && tokens->operators & (OR_IF | AND_IF))
		return (SUCCESS);
	return (FAILURE);
}

int	ft_operators_intercmd(void *ptr)
{
	t_tkn	*tokens;

	if (!ptr)
		return (FAILURE);
	tokens = ptr;
	if (tokens && !tokens->found && tokens->operators & PIPE)
		return (SUCCESS);
	return (FAILURE);
}

int	ft_operators_intracmd(void *ptr)
{
	t_tkn	*tokens;

	if (!ptr)
		return (FAILURE);
	tokens = ptr;
	if (tokens && !tokens->found
		&& tokens->operators & (DGREATER | GREATER | LOWER | DLOWER))
		return (SUCCESS);
	return (FAILURE);
}

int	ft_tokens_word(void *ptr)
{
	t_tkn	*tokens;

	if (!ptr)
		return (FAILURE);
	tokens = ptr;
	if (tokens && tokens->token & WORD)
		return (SUCCESS);
	return (FAILURE);
}

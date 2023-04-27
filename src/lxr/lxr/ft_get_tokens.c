/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:17:24 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/26 09:38:31 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

/*
	Return Value Status
	O				ALL OK.
	1				NOT added to list.
	NOT_TOKEN		NOT Complete value "' doesn't not end.
*/
static void	*ft_add_to_lst(t_lxr *lxr)
{
	t_tkn	*token;
	t_btree	*node;

	token = ft_init_tkn(&lxr->tokens);
	if (!token)
	{
		ft_btree_clear(&lxr->btree, ft_destroy_tkn);
		free(lxr);
		return (NULL);
	}
	node = ft_btree_new_node(token);
	if (!node)
	{
		ft_btree_clear(&lxr->btree, ft_destroy_tkn);
		free(lxr);
		ft_destroy_tkn(token);
		return (NULL);
	}
	ft_lstadd_back((t_list **)&lxr->btree, (t_list *)node);
	return ((void *)node);
}

int	ft_get_tokens(t_lxr *lxr)
{
	int	result;

	while (lxr->str[lxr->pos])
	{
		lxr->pos += ft_run_ifs(lxr);
		if (!lxr->str[lxr->pos])
			return (NOT_TOKEN);
		result = ft_operators(lxr);
		if (result == NOT_TOKEN)
			return (NOT_TOKEN);
		else if (result)
		{
			result = ft_token_varname(lxr);
			if (result == NOT_TOKEN)
				return (NOT_TOKEN);
			else if (result == FAILURE)
				return (FAILURE);
		}
		if (ft_add_to_lst(lxr) == NULL)
			return (FAILURE);
	}
	return (SUCCESS);
}

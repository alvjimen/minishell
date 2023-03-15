/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:17:24 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/15 18:56:02 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

/*
	Return Value Status
	O				ALL OK.
	1				NOT added to list.
	NOT_TOKEN		NOT Complete value "' doesn't not end.
*/
void	*ft_add_to_lst(t_lxr *lxr)
{
	t_tkn	*token;
	t_list	*node;

	token = ft_init_tkn(&lxr->tokens);
	if (!token)
		return (NULL);
	node = ft_lstnew(token);
	if (!node)
	{
		free(token);
		return (NULL);
	}
	ft_lstadd_back(&lxr->lst, node);
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
			if (ft_token_varname(lxr) == NOT_TOKEN)
				return (NOT_TOKEN);
		if (ft_add_to_lst(lxr) == NULL)
			return (1);
	}
	return (0);
}

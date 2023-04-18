/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_builder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 12:18:57 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/18 13:57:35 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

t_btree	*ft_btree_builder(char	*str)
{
	t_lxr	*lxr;

	if (!str)
		return (NULL);
	lxr = ft_init_lxr(str);
	if (!lxr)
		return (NULL);
	if (ft_get_tokens(lxr) == FAILURE)
	{
		free(lxr);
		return (NULL);
	}
	if (ft_syntax_analizer(lxr->btree, lxr) != SUCCESS)
	{
		ft_btree_clear(&lxr->btree, ft_destroy_tkn);
		free(lxr);
		return (NULL);
	}
	ft_btree_apply_to_node_pointer_infix(&lxr->btree,
		ft_operators_split_recursively);
	ft_btree_apply_to_node_pointer_infix(&lxr->btree,
		ft_parenthesis_expansion_recursively);
	return (lxr->btree);
}

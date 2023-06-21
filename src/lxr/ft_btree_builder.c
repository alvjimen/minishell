/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_builder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 12:18:57 by alvjimen          #+#    #+#             */
/*   Updated: 2023/06/18 14:35:04 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

static void	*ft_clean_builder(t_btree **root, t_lxr *lxr, int flag)
{
	if (flag > 1)
		ft_btree_clear(root, ft_destroy_tkn);
	if (flag > 0)
		free(lxr);
	return (NULL);
}

t_btree	*ft_btree_builder(char	*str)
{
	t_lxr	*lxr;
	t_btree	*root;

	if (!str)
		return (NULL);
	lxr = ft_init_lxr(str);
	if (!lxr)
		return (NULL);
	if (ft_get_tokens(lxr) == FAILURE)
		return (ft_clean_builder(&lxr->btree, lxr, 1));
	if (ft_syntax_analizer(lxr->btree, lxr) != SUCCESS)
		return (ft_clean_builder(&lxr->btree, lxr, 2));
	ft_btree_apply_to_node_pointer_infix(&lxr->btree,
		ft_operators_split_recursively);
	ft_btree_apply_to_node_pointer_infix(&lxr->btree,
		ft_parenthesis_expansion_recursively);
	root = lxr->btree;
	free(lxr);
	return (root);
}

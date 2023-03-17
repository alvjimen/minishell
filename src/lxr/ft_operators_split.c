/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operators_split.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:23:30 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/17 13:29:49 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

/*
	if return 0 OK
	if return 1 KO
*/
int	ft_operators_split(t_btree *root)
{
	t_btree	*node;

	if (!root)
		return (1);
	node = (t_btree *)ft_split_list((t_list *)root, ft_operators_interpipelines);
	if (node)
	{
		ft_btree_add_parent(root, ft_btree_add_left);
		return (0);
	}
	node = (t_btree *)ft_split_list((t_list *)root, ft_operators_intercmd);
	if (node)
	{
		ft_btree_add_parent(root, ft_btree_add_left);
		return (0);
	}
	node = (t_btree *)ft_search_list((t_list *)root, ft_operators_intracmd);
	/*
	if (node)
		Comming Soon
	*/
	return (0);
}

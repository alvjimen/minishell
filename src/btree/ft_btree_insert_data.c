/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:45:50 by alvjimen          #+#    #+#             */
/*   Updated: 2023/02/25 16:50:57 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "btree.h"

void	ft_btree_insert_data(t_btree **root, void *item,
	int (*cmpf)(void *, void*))
{
	if (!root || !*root)
	{
		*root = ft_btree_new_node(item);
		return ;
	}
	if (cmpf(root[0]->content, item) < 0)
	{
		if (!root[0]->left)
		{
			root[0]->left = ft_btree_new_node(item);
			return ;
		}
		ft_btree_insert_data(&root[0]->left, item, (*cmpf));
	}
	else
	{
		if (!root[0]->right)
		{
			root[0]->right = ft_btree_new_node(item);
			return ;
		}
		ft_btree_insert_data(&root[0]->right, item, (*cmpf));
	}
}

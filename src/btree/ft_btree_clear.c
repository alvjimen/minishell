/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:23:44 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/05 13:05:08 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "btree.h"

void	ft_btree_clear(t_btree	**root, void (*clean)(void *))
{
	if (!root || !root[0] || !clean)
		return ;
	if (root[0] && root[0]->left)
		ft_btree_clear(&root[0]->left, clean);
	if (root[0] && root[0]->right)
		ft_btree_clear(&root[0]->right, clean);
	if (root[0])
		ft_btree_delone(*root, clean);
	*root = NULL;
}

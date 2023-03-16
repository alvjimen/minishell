/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_add_parent.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:08:06 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/16 20:08:18 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "btree.h"

void	ft_btree_add_parent(t_btree **root, t_btree *node,
	(*f)(t_btree *, t_btree *))
{
	t_btree	*tmp;

	if (!root || !node)
		return ;
	tmp = *root;
	*root = node;
	f(node, tmp);
}

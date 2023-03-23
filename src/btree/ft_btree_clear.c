/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:23:44 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/23 12:41:38 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "btree.h"

void	ft_btree_clear(t_btree	**root, void (*clean)(void *))
{
	if (!root || !*root || !(*clean))
		return ;
	ft_btree_clear(&root[0]->left, clean);
	ft_btree_clear(&root[0]->right, clean);
	ft_btree_delone(*root, clean);
	*root = NULL;
}

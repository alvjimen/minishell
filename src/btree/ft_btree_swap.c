/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:38:16 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/18 19:42:00 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "btree.h"

void	ft_btree_swap(void *ptr)
{
	t_btree	*root;
	t_btree	*tmp;

	if (!ptr)
		return ;
	root = ptr;
	tmp = root->right;
	root->right = root->left;
	root->left = tmp;
}

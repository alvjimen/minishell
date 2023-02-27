/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_infix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:17:56 by alvjimen          #+#    #+#             */
/*   Updated: 2023/02/25 16:44:36 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "btree.h"

void	ft_btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return ;
	applyf(root->content);
	ft_btree_apply_infix(root->left,applyf);
	ft_btree_apply_infix(root->right,applyf);
}


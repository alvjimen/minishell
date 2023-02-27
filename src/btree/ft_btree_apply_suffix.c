/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_suffix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:45:45 by alvjimen          #+#    #+#             */
/*   Updated: 2023/02/25 16:45:50 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "btree.h"

void	ft_btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return ;
	ft_btree_apply_suffix(root->left,applyf);
	ft_btree_apply_suffix(root->right,applyf);
	applyf(root->content);
}

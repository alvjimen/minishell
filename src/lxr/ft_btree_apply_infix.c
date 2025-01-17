/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_infix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:17:56 by alvjimen          #+#    #+#             */
/*   Updated: 2023/06/18 15:19:34 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "btree.h"

void	ft_btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return ;
	applyf(root->content);
	ft_btree_apply_infix(root->left, applyf);
	ft_btree_apply_infix(root->right, applyf);
}

/*
	applyf don't do bad things
*/
void	ft_btree_apply_to_node_infix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return ;
	applyf(root);
	ft_btree_apply_infix(root->left, applyf);
	ft_btree_apply_infix(root->right, applyf);
}

void	ft_btree_apply_to_node_pointer_infix(t_btree **root,
		void (*applyf)(void **))
{
	if (!root || !*root)
		return ;
	applyf((void **)root);
	if (root[0] && root[0]->left)
		ft_btree_apply_to_node_pointer_infix (&root[0]->left, applyf);
	if (root[0] && root[0]->right)
		ft_btree_apply_to_node_pointer_infix(&root[0]->right, applyf);
}

void	ft_btree_apply_to_node_pointer_infix_param(t_btree **root, void *ptr,
		void (*applyf)(void **, void *))
{
	if (!root || !*root)
		return ;
	applyf((void **)root, ptr);
	if (root[0] && root[0]->left)
		ft_btree_apply_to_node_pointer_infix_param(&root[0]->left,
			ptr, applyf);
	if (root[0] && root[0]->right)
		ft_btree_apply_to_node_pointer_infix_param(&root[0]->right,
			ptr, applyf);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_modify_root_conserve_branchs.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 21:12:37 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/18 19:21:19 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "btree.h"

t_btree	*ft_btree_left_leave(t_btree *root)
{
	if (!root)
		return (NULL);
	while (root->left)
		root = root->left;
	return (root);
}

t_btree	*ft_btree_right_leave(t_btree *root)
{
	if (!root)
		return (NULL);
	while (root->right)
		root = root->right;
	return (root);
}

static void	ft_set_root(t_btree **root, t_btree *left, t_btree *right)
{
	if (!*root && right)
	{
		*root = right;
		right = NULL;
	}
	else if (!*root && left)
	{
		*root = left;
		left = NULL;
	}
}

static void	ft_set_branch(t_btree **root, t_btree *left, t_btree *right)
{
	t_btree	*aux;

	if (right && root[0]->right != right)
	{
		aux = ft_btree_right_leave(root[0]);
		if (aux)
			aux->right = right;
	}
	if (left && root[0]->left != left)
	{
		aux = ft_btree_left_leave(root[0]);
		if (aux)
			aux->left = left;
	}
}

void	ft_btree_modify_root_conserve_branchs(t_btree **root,
		void (*f)(t_btree **root))
{
	t_btree	*right;
	t_btree	*left;

	if (!root || !*root)
		return ;
	right = root[0]->right;
	left = root[0]->left;
	(*f)(root);
	while (root[0] && root[0] == right)
	{
		right = root[0]->right;
		left = root[0]->left;
		(*f)(root);
	}
	ft_set_root(root, left, right);
	ft_set_branch(root, left, right);
}

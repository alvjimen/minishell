/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_root_conserve_branchs.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 21:12:37 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/05 17:01:53 by alvjimen         ###   ########.fr       */
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

void	ft_btree_modify_root_conserve_branchs(t_btree **root,
		void (*f)(t_btree  **root))
{
	t_btree	*right;
	t_btree	*left;
	t_btree	*aux;

	if (!root || !*root)
		return ;
	right = root[0]->right;
	left = root[0]->left;
	(*f)(root);
	aux = ft_btree_right_leave(root[0]);
	if (aux)
		aux->right = right;
	aux = ft_btree_left_leave(root[0]);
	if (aux)
		aux->left = left;
}

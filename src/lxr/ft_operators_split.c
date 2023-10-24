/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operators_split.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:23:30 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/24 14:02:16 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

/*
	if return 0 SUCCESS
	if return 1 FAILURE
*/
int	ft_tokens_paren(void *ptr)
{
	t_tkn	*tokens;

	if (!ptr)
		return (FAILURE);
	tokens = ptr;
	if (tokens && tokens->token == PARENTHESIS)
		return (SUCCESS);
	return (FAILURE);
}

int	ft_operators_outercmd(t_btree **root, int (*f)(void *))
{
	t_btree	*node;

	node = (t_btree *)ft_split_list((t_list **)root,
			f);
	if (node)
	{
		ft_btree_add_parent(root, node, ft_btree_add_left);
		return (SUCCESS);
	}
	return (FAILURE);
}

int	ft_operators_redirections(t_btree **root)
{
	t_btree	*node;
	t_btree	*aux;
	t_tkn	*content;

	node = (t_btree *)ft_split_list_first((t_list **)root,
			ft_operators_intracmd);
	if (!node)
		return (FAILURE);
	aux = root[0];
	root[0] = node;
	if (aux != node)
		ft_lstadd_back((t_list **)&node->left, (t_list *)aux);
	if (root[0]->right)
	{
		ft_lstadd_back((t_list **)&node->left, (t_list *)node->right->right);
		node->right->right = NULL;
	}
	return (SUCCESS);
}

int	ft_operators_split(t_btree **root)
{
	t_btree	*node;
	t_btree	*aux;
	t_tkn	*content;

	if (!root || !*root)
		return (FAILURE);
	if (ft_operators_outercmd(root, ft_operators_interpipelines) == SUCCESS)
		return (SUCCESS);
	else if (ft_operators_outercmd(root, ft_operators_intercmd) == SUCCESS)
		return (SUCCESS);
	ft_operators_redirections(root);
	return (SUCCESS);
}

void	ft_operators_split_recursively(void **ptr)
{
	t_btree	**root;

	root = (t_btree **)ptr;
	ft_operators_split(root);
}

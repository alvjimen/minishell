/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operators_split.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:23:30 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/23 13:22:14 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

/*
	if return 0 OK
	if return 1 KO
*/
int	ft_tokens_paren(void *ptr)
{
	t_tkn	*tokens;

	if (!ptr)
		return (FAILURE);
	tokens = ptr;
	if (tokens && tokens->token & PARENTHESIS)
		return (SUCCESS);
	return (FAILURE);
}

int	ft_operators_split(t_btree **root)
{
	t_btree	*node;
	t_btree	*args;
	t_tkn	*content;
	t_tkn	*tkn_arg;
	size_t	lst_size;

	if (!root || !*root)
		return (FAILURE);
	/*|| &&*/
	node = (t_btree *)ft_split_list((t_list **)root,
			ft_operators_interpipelines);
	if (node)
	{
		ft_btree_add_parent(root, node, ft_btree_add_left);
		return (SUCCESS);
	}
	/*|*/
	node = (t_btree *)ft_split_list((t_list **)root,
			ft_operators_intercmd);
	if (node)
	{
		ft_btree_add_parent(root, node, ft_btree_add_left);
		return (SUCCESS);
	}
	/*< > << >> */
	node = (t_btree *)ft_split_list((t_list **)root,
			ft_operators_intracmd);
	if (node)
	{
		while (node)
		{
			ft_btree_swap(*root);
			ft_lstadd_back((t_list **)root, (t_list *)root[0]->left->right);
			root[0]->left->right = NULL;
			node = (t_btree *)ft_split_list((t_list **)root,
					ft_operators_intracmd);
		}
		ft_btree_apply_to_node_infix(*root, ft_btree_swap);
	}
	/*()*/
	if (!ft_tokens_paren(root[0]->content))
	{
		content = root[0]->content;
		if (ft_parenthesis_split(content->value, root))
			return (FAILURE);
	}
	/*Create the array of str*/
	/*Acceder a la posición del árbol que tiene las palabras*/
	node = *root;
	while (node->left)
		node = node->left;
	/*Comprobar que si haya ASSIGNMENT_WORD y despues palabras*/
	content = node->content;
	if (content->token & ASSIGNMENT_WORD)
	{
		args = (t_btree *)ft_split_list((t_list **)&node, ft_tokens_word);
		ft_lstclear((t_list **)&args, ft_destroy_tkn);
	}
	/*Crear una array de 2D apartir de una lista*/
	/*PDTE usar sarr on this part*/
	lst_size = ft_lstsize((t_list *)node);
	content = node->content;
	content->str = ft_calloc(lst_size + 1, sizeof(char *));
	if (!content->str)
		return (FAILURE);
	args = node;
	lst_size = 0;
	while (args)
	{
		tkn_arg = args->content;
		content->str[lst_size++] = ft_strdup(tkn_arg->value);
		args = args->right;
	}
	/*Destroy the element of the args*/
	ft_lstclear((t_list **)&node->right, ft_destroy_tkn);
	return (SUCCESS);
}

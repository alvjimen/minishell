/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operators_split.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:23:30 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/31 15:55:37 by alvjimen         ###   ########.fr       */
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

	node = (t_btree *)ft_split_list((t_list **)root,
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
	/*
	t_btree	*args;
	t_tkn	*tkn_arg;
	size_t	lst_size;
	*/

	if (!root || !*root)
		return (FAILURE);
	/*|| &&*/
	if (ft_operators_outercmd(root, ft_operators_interpipelines) == SUCCESS)
		return (SUCCESS);
	/*|*/
	else if (ft_operators_outercmd(root, ft_operators_intercmd) == SUCCESS)
		return (SUCCESS);
	else if (ft_operators_redirections(root) == SUCCESS)
		return (SUCCESS);
	/*< > << >> */
	/*if want to stay the the first file on top and the last on bottom execute this recursively
	*/
	node = (t_btree *)ft_split_list((t_list **)root,
			ft_operators_intracmd);
	if (node)
	{
		/*Is not working fine*/
		//while (node)
		//{
			/*save the root*/
			aux = root[0];
			/*Put the new root*/
			root[0] = node;
			/*If the old root and the new root is the same */
			if (aux != node)
				ft_lstadd_back((t_list **)&node->left, (t_list *)aux);
			/*Swap the branch of the root*/
			//ft_btree_swap(*root);
			/*
			Si tenemos algo después del operador cogemos
			el siguiente de ese operador lo añadimos a la otra rama y eso que estaba
			antes en  los siguiente del operador y lo igualamos a nulo
			*/
			/*
			if (root[0]->left)
			{
				ft_lstadd_back((t_list **)root, (t_list *)root[0]->left->right);
				root[0]->left->right = NULL;
			}
			*/
			if (root[0]->right)
			{
				ft_lstadd_back((t_list **)node->left,
					(t_list *)node->right->right);
				root[0]->right->right = NULL;
			}/*
			   Esto es para simular la recursividad pero vamos hacerlo un  poco mejor
			*/
			/*
				node = (t_btree *)ft_split_list((t_list **)root,
					ft_operators_intracmd);
			*/
		//}
		/*
		ft_btree_swap(*root);
		*/
		//ft_btree_apply_to_node_infix(*root, ft_btree_swap);
	}
	/*This is part of another function an is should execute later*/
	/*()*/
	/*
	if (!ft_tokens_paren(root[0]->content))
	{
		content = root[0]->content;
		if (ft_parenthesis_split(content->value, root))
			return (FAILURE);
	}
	*/
	/*Create the array of str*/
	/*Acceder a la posición del árbol que tiene las palabras*/
	/*
	node = *root;
	while (node->left)
		node = node->left;
	*/
	/*Comprobar que si haya ASSIGNMENT_WORD y despues palabras*/
	/*
	content = node->content;
	if (content->token == ASSIGNMENT_WORD)
	{
		args = (t_btree *)ft_split_list((t_list **)&node, ft_tokens_word);
		ft_lstclear((t_list **)&args, ft_destroy_tkn);
	}
	*/
	/*Crear una array de 2D apartir de una lista*/
	/*PDTE usar sarr on this part*/
	/*
	content = node->content;
	args = node;
	lst_size = 0;
	while (args)
	{
		tkn_arg = args->content;
		content->str[lst_size++] = ft_strdup(tkn_arg->value);
		args = args->right;
	}
	*/
	/*Destroy the element of the args*/
	/*
	ft_lstclear((t_list **)&node->right, ft_destroy_tkn);
	*/
	return (SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax_analizer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:03:33 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/04 09:28:06 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"
/*this is executes before get_tokens any ft_split*/

int	ft_syntax_analizer_word(t_btree *root, t_tkn *content, t_lxr *lxr)
{
	if (content->token == WORD || content->token == ASSIGNMENT_WORD)
	{
		if (!root->right)
			return (SUCCESS);
		content = root->right->content;
		if (!content || content->token == PARENTHESIS)
			return (FAILURE);
		return (SUCCESS);
	}
	return (ft_syntax_analizer_paren(root, content, lxr));
}

int	ft_syntax_analizer_paren(t_btree *root, t_tkn *content, t_lxr *lxr)
{
	if (content->token == PARENTHESIS)
	{
		if (!content->value || ft_strlen(content->value) <= 2)
			return (FAILURE);
		if (!root->right)
			return (SUCCESS);
		content = root->right->content;
		if (!content || (content->token == ASSIGNMENT_WORD
			|| content->token == WORD))
			return (FAILURE);
		return (SUCCESS);
	}
	return (ft_syntax_analizer_operator(root, content, lxr));
}

int	ft_syntax_analizer_operator(t_btree *root, t_tkn *content, t_lxr *lxr)
{
	if (content->token == OPERATOR && (content->operators == AND_IF
		|| content->operators == OR_IF || content->operators == PIPE))
	{
		if (root == lxr->btree)
			return (FAILURE);
		if (!root->right)
			return (FAILURE);
		content = root->right->content;
		if (!content && content->token == OPERATOR && (content->operators == AND_IF
			|| content->operators == OR_IF || content->operators == PIPE))
			return (FAILURE);
		return (SUCCESS);
	}
	else if (content->token == OPERATOR && (content->operators == DGREATER
		|| content->operators == GREATER || content->operators == LOWER
		|| content->operators == DLOWER))
	{
		if (!root->right)
			return (FAILURE);
		content = root->right->content;
		if (!content || content->token == OPERATOR || content->token == PAREN)
			return (FAILURE);
		return (SUCCESS);
	}
	return (NOT_TOKEN);
}

int	ft_syntax_analizer(t_btree *root, t_lxr *lxr)
{
	t_tkn	*content;
	int		result;

	if (!root)
		return (NOT_TOKEN);
	while (root)
	{
		content = root->content;
		if (!content)
		{
			root = root->right;
			continue ;
		}
		result = ft_syntax_analizer_word(root, content, lxr);
		if (result == FAILURE)
			return (FAILURE);
		/*
		else if (result == NOT_TOKEN)
			ft_putstr_fd("empty input", 1);
		*/
		root = root->right;
	}
	return (SUCCESS);
}

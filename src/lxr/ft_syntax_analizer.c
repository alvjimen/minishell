/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax_analizer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:03:33 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/12 19:07:37 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"
/*this is executes before get_tokens any ft_split*/

static int	ft_syntax_analizer_operator_intercmd(t_btree *root, t_tkn *content)
{
	if (!root->right)
		return (FAILURE);
	content = root->right->content;
	if (!content || content->token == OPERATOR || content->token == PAREN)
		return (FAILURE);
	content->token = FILENAME;
	if (((t_tkn *)(root->content))->operators == DLOWER)
		content->token = HDFILENAME;
	return (SUCCESS);
}

static int	ft_syntax_analizer_operator(t_btree *root, t_tkn *content,
		t_lxr *lxr)
{
	if (content->token == OPERATOR && (content->operators == AND_IF
			|| content->operators == OR_IF || content->operators == PIPE))
	{
		if (root == lxr->btree)
			return (FAILURE);
		if (!root->right)
			return (FAILURE);
		content = root->right->content;
		if (!content || (content->token == OPERATOR
			&& (content->operators == AND_IF || content->operators == OR_IF
				|| content->operators == PIPE)))
			return (FAILURE);
		return (SUCCESS);
	}
	else if (content->token == OPERATOR && (content->operators == DGREATER
			|| content->operators == GREATER || content->operators == LOWER
			|| content->operators == DLOWER))
		return (ft_syntax_analizer_operator_intercmd(root, content));
	return (FAILURE);
}

static int	ft_syntax_analizer_paren(t_btree *root, t_tkn *content, t_lxr *lxr)
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

static int	ft_syntax_analizer_word(t_btree *root, t_tkn *content, t_lxr *lxr)
{
	if (content->token == WORD || content->token == ASSIGNMENT_WORD
		|| content->token == FILENAME || content->token == HDFILENAME)
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
		{
			content->token = SYNTAX_ERROR;
			return (FAILURE);
		}
		root = root->right;
	}
	return (SUCCESS);
}

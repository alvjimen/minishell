/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax_analizer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:03:33 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/23 13:38:59 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"
/*this is executes before get_tokens any ft_split*/

int	ft_syntax_analizer_word(t_btree *root, t_tkn *content, t_lxr *lxr)
{
	if (content->token & (WORD | ASSIGNMENT_WORD))
	{
		if (!root->right)
			return (SUCCESS);
		content = root->right->content;
		if (!content || content->token & PARENTHESIS)
			return (FAILURE);
		return (SUCCESS);
	}
	return (ft_syntax_analizer_paren(root, content, lxr));
}

int	ft_syntax_analizer_paren(t_btree *root, t_tkn *content, t_lxr *lxr)
{
	if (content->token & PARENTHESIS)
	{
		if (!root->right)
			return (SUCCESS);
		content = root->right->content;
		if (!content || content->token & (ASSIGNMENT_WORD | WORD))
			return (FAILURE);
		return (SUCCESS);
	}
	return (ft_syntax_analizer_operator(root, content, lxr));
}

int	ft_syntax_analizer_operator(t_btree *root, t_tkn *content, t_lxr *lxr)
{
	if (content->token & OPERATOR
		&& content->operators & (AND_IF | OR_IF | PIPE))
	{
		if (root == lxr->btree)
			return (FAILURE);
		if (!root->right)
			return (FAILURE);
		content = root->right->content;
		if (!content && content->token & OPERATOR
			&& content->operators & (AND_IF | OR_IF | PIPE))
			return (FAILURE);
		return (SUCCESS);
	}
	else if (content->token & OPERATOR
		&& content->operators & (DGREATER | GREATER | LOWER | DLOWER))
	{
		if (!root->right)
			return (FAILURE);
		content = root->right->content;
		if (!content || content->token & (OPERATOR | PAREN))
			return (FAILURE);
		return (SUCCESS);
	}
	return (NOT_TOKEN);
}

int	ft_syntax_analizer(t_lxr *lxr)
{
	t_btree	*root;
	t_tkn	*content;
	int		result;

	root = lxr->btree;
	if (!root)
		return (FAILURE);
	while (root)
	{
		content = root->content;
		if (!content)
			return (FAILURE);
		result = ft_syntax_analizer_word(root, content, lxr);
		if (result == FAILURE)
			return (FAILURE);
		else if (result == NOT_TOKEN)
			ft_putstr_fd("empty input", 1);
		root = root->right;
	}
	return (SUCCESS);
}

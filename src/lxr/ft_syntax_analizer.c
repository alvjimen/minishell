/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax_analizer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:03:33 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/20 17:13:40 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"
/*this is executes before get_tokens any ft_split*/
int	ft_syntax_analizer(t_lxr *lxr)
{
	t_btree	*root;
	t_tkn	*content;

	root = lxr->btree;
	if (!root)
		return (0);
	while (root)
	{
		content = root->content;
		if (!content)
			continue ;
		if (content->token & (WORD | ASSIGNMENT_WORD))
		{
			if (!root->right)
				return (0);
			content = root->right->content;
			if (!content)
				continue ;
			if (content->token & PARENTHESIS)
				return (1);
		}
		else if (content->token & PARENTHESIS)
		{
			if (!root->right)
				return (0);
			content = root->right->content;
			if (!content)
				continue ;
			if (content->token & (ASSIGNMENT_WORD | WORD))
				return (1);
		}
		else if (content->token & OPERATOR)
		{
			if (content->operators & (AND_IF | OR_IF | PIPE))
			{
				if (root == lxr->btree)
					return (1);
				if (!root->right)
					return (1);
				content = root->right->content;
				if (!content)
					continue ;
				if (content->token & OPERATOR && content->operators & (AND_IF | OR_IF | PIPE))
					return (1);
			}
			else if (content->operators & (DGREATER | GREATER | LOWER | DLOWER))
			{
				if (!root->right)
					return (1);
				content = root->right->content;
				if (!content)
					continue ;
				if (content->token & (OPERATOR | PAREN))
					return (1);
			}
		}
		root = root->right;
	}
	return (0);
}

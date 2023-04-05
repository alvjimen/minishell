/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parenthesis_split.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 08:09:01 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/05 22:08:35 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

/*
	return value Status
	0				ALL OK.
	1				ERROR
*/
int	ft_clean_exit(t_lxr **lxr, char **tmp, int flag)
{
	if (flag > 0)
	{
		free(*tmp);
		*tmp = NULL;
		if (flag > 1)
		{
			free(*lxr);
			*lxr = NULL;
		}
	}
	return (flag != 3);
}

int	ft_split_inner_parenthesis(t_lxr *lxr, t_btree **root)
{
	int	len;

	len = ft_get_tokens(lxr);
	if (len == NOT_TOKEN || len == FAILURE)
		return (FAILURE);
	ft_lstiter((t_list *)lxr->btree, ft_print_lst);
	len = ft_operators_split(&lxr->btree);
	if (len == FAILURE)
		return (FAILURE);
	ft_btree_delone(*root, ft_destroy_tkn);
	*root = lxr->btree;
	return (SUCCESS);
}

/*if (len <= 2) the len is checked on syntax analizer*/
int	ft_parenthesis_split(char	*str, t_btree **root)
{
	size_t	len;
	char	*tmp;
	t_lxr	*lxr;

	if (!str || !root || !*root)
		return (FAILURE);
	len = ft_strlen(str);
	if (len <= 2)
		return (FAILURE);
	tmp = ft_substr(str, 1, len - 2);
	if (!tmp)
		return (FAILURE);
	lxr = ft_init_lxr(tmp);
	if (!lxr)
		return (ft_clean_exit(&lxr, &tmp, 1));
	if (ft_split_inner_parenthesis(lxr, root))
		return (ft_clean_exit(&lxr, &tmp, 2));
	if (ft_syntax_analizer(*root, lxr) == SUCCESS)
		return (ft_clean_exit(&lxr, &tmp, 3));
	return (ft_clean_exit(&lxr, &tmp, 2));
}

/*This is part of another function an is should execute later*/
/*()*/
/* This is function should pass once the tree is all build for
	subtitute the paren token with her content it doesn't care about
	what is next use when is a leave of the tree in other case
	may create leaks save the next part before use this function.
*/
void	ft_parenthesis_expansion_recursively(void **ptr)
{
	t_btree	**root;
	t_tkn	*content;

	root = (t_btree **)ptr;
	if (ft_tokens_paren(root[0]->content))
		return ;
	content = root[0]->content;
	/*ft_btree_modify_root_conserve_branchs(root, ft_unquote_quotes);*/
	if (ft_parenthesis_split(content->value, root))
	{
		content->token = ERROR;
		return ;
	}
}

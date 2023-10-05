/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parenthesis_split.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 08:09:01 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/05 18:16:08 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

/*
	return value Status
	0				ALL OK.
	1				ERROR
*/
/*
static int	ft_clean_exit(t_lxr **lxr, char **tmp, int flag)
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

static int	ft_split_inner_parenthesis(t_lxr *lxr, t_btree **root)
{
	int	len;

	len = ft_get_tokens(lxr);
	if (len == NOT_TOKEN || len == FAILURE)
		return (FAILURE);
//	ft_lstiter((t_list *)lxr->btree, ft_print_lst);
	len = ft_operators_split(&lxr->btree);
	if (len == FAILURE)
		return (FAILURE);
	ft_btree_delone(*root, ft_destroy_tkn);
	*root = lxr->btree;
	return (SUCCESS);
}
*/

/*if (len <= 2) the len is checked on syntax analizer*/
int	ft_parenthesis_split(char	*str, t_btree **root)
{
	size_t	len;
	char	*tmp;

	if (!str || !root || !*root)
		return (FAILURE);
	len = ft_strlen(str);
	if (len <= 2)
		return (FAILURE);
	tmp = ft_substr(str, 1, len - 2);
	if (!tmp)
		return (FAILURE);
	ft_btree_clear(root, ft_destroy_tkn);
	*root = ft_btree_builder(tmp);
	free(tmp);
	if (*root)
		return (SUCCESS);
	return (FAILURE);
}

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
	if (ft_parenthesis_split(content->value, root))
	{
		content->token = ERROR;
		return ;
	}
}

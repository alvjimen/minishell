/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parenthesis_split.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 08:09:01 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/24 12:37:18 by alvjimen         ###   ########.fr       */
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
	size_t	len;

	len = ft_get_tokens(lxr);
	if ((int)len == NO_TOKEN || (int)len == 1)
		return (ft_clean_exit(&lxr, &tmp, 2));
	ft_lstiter((t_list *)lxr->btree, ft_print_lst);
	len = ft_operators_split(&lxr->btree);
	if (len == 1)
		return (FAILURE);
	ft_btree_delone(root[0]);
	*root = lxr->btree;
	return (SUCCESS);
}

int	ft_parenthesis_split(char	*str, t_btree **root)
{
	size_t	len;
	char	*tmp;
	t_lxr	*lxr;

	if (!str || !root || !*root)
		return (FAILURE);
	len = ft_strlen(str);
	if (len < 2)
		return (FAILURE);
	tmp = ft_substr(str, 1, len - 2);
	if (!tmp)
		return (FAILURE);
	lxr = ft_init_lxr(tmp);
	if (!lxr)
		return (ft_clean_exit(&lxr, &tmp, 1));
	if (ft_split_inner_parenthesis(lxr, root))
		return (ft_clean_exit(&lxr, &tmp, 2));
	return (ft_clean_exit(&lxr, &tmp, 3));
}

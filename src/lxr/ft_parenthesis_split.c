/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parenthesis_split.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 08:09:01 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/22 21:32:53 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

/*
	return value Status
	0				ALL OK.
	1				Paremeter error
	2				Syntax error.
	3				Malloc error
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
	if (flag == 3)
		return (0);
	return (1);
}

int	ft_split_inner_parenthesis(t_lxr *lxr, t_btree **root)
{
	size_t	len;

	len = ft_get_tokens(lxr);
	if (len & (NO_TOKEN | 1))
		return (ft_clean_exit(&lxr, &tmp, 2));
	len = ft_operators_split(&lxr->btree);
	if (len == 1)
		return (1);
	ft_destroy_tkn(root[0]->content);
	free(*root);
	*root = lxr->btree;
	free(lxr);
	return (0);
}
int	ft_parenthesis_split(char	*str, t_btree **root)
{
	size_t	len;
	char	*tmp;
	t_lxr	*lxr;

	if (!str || !root || !*root)
		return (1);
	len = ft_strlen(str);
	if (len < 2)
		return (1);
	tmp = ft_substr(str, 1, len - 2);
	if (!tmp)
		return (1);
	lxr = ft_init_lxr(tmp);
	if (!lxr)
		return (ft_clean_exit(&lxr, &tmp, 1));
		/**/
	len = ft_get_tokens(lxr);
	if (len & (NO_TOKEN | 1))
		return (ft_clean_exit(&lxr, &tmp, 2));
	len = ft_operators_split(&lxr->btree);
	if (len == 1)
		return (1);
	ft_destroy_tkn(root->content);
	free(*root);
	*root = lxr->btree;
	return (ft_clean_exit(&lxr, &tmp, 3);
}

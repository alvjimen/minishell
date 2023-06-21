/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unquote_quotes_regex_utils.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 09:10:06 by alvjimen          #+#    #+#             */
/*   Updated: 2023/06/18 15:28:58 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

void	*ft_unquote_quotes_regex_new_tkns(t_lxr *lxr, t_tkn *content, char *str)
{
	ft_bzero(lxr, sizeof(t_lxr));
	lxr->str = str;
	if (ft_get_tokens(lxr) != SUCCESS)
	{
		free(lxr->str);
		free(lxr);
		content->token = ERROR;
		return (NULL);
	}
	if (!lxr->str[0])
	{
		free(lxr);
		free(content->value);
		content->value = lxr->str;
		return (NULL);
	}
	return (lxr->str);
}

void	ft_unquote_quotes_regex_set_filename(t_lxr *lxr, t_tkn *content)
{
	if (content->token == FILENAME || content->token == HDFILENAME)
	{
		if (content->token == FILENAME)
			ft_lstiter((t_list *)lxr->btree, ft_set_filename);
		else if (content->token == HDFILENAME)
			ft_lstiter((t_list *)lxr->btree, ft_set_hdfilename);
		if (ft_lstsize((t_list *)lxr->btree) > 1)
			ft_lstiter((t_list *)lxr->btree, ft_set_ambiguous);
	}
}

void	*ft_unquote_quotes_regex_new_root(t_lxr **lxr, t_btree **root)
{
	ft_btree_delone(root[0], ft_destroy_tkn);
	root[0] = NULL;
	*root = lxr[0]->btree;
	free(lxr[0]->str);
	free(lxr[0]);
	if (!*root || !root[0]->content)
		return (NULL);
	return (root);
}

int	ft_unquote_quotes_aux_clean(char *str, t_lxr *lxr,
		t_btree **root, t_tkn *content)
{
	if (!str)
		return (1);
	if (!*str)
	{
		free(lxr);
		free(str);
		ft_btree_delone(*root, ft_destroy_tkn);
		root[0] = NULL;
		return (1);
	}
	if (ft_unquote_quotes_regex_new_tkns(lxr, content, str) == NULL)
		return (1);
	return (0);
}

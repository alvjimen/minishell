/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unquote_quotes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:18:10 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/22 13:55:49 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

t_quotes	*ft_unquote_quotes_regex_expand_inside(t_lxr **lxr, t_tkn *content)
{
	t_quotes	*quotes;
	char		*str;

	*lxr = ft_init_lxr(content->value);
	if (!*lxr)
	{
		content->token = ERROR;
		return (NULL);
	}
	quotes = ft_init_quotes(*lxr);
	if (!quotes)
	{
		free(*lxr);
		content->token = ERROR;
		return (NULL);
	}
	if (content->token != HDFILENAME && ft_expand_inside_quotes(quotes) == NULL)
	{
		free(*lxr);
		ft_destroy_quotes(&quotes);
		content->token = ERROR;
	}
	return (quotes);
}

void	ft_unquote_quotes_regex_expand_regex(t_tkn *content, t_quotes *quotes,
		t_lxr *lxr)
{
	content->regex = ft_regex_ls(quotes, lxr->str);
	ft_destroy_quotes(&quotes);
	free(lxr);
	if (!content->regex)
	{
		content->token = ERROR;
		return ;
	}
	free(content->value);
	content->value = ft_strdup(content->regex[0]);
	if (!content->value)
		content->token = ERROR;
	return ;
}

void	ft_unquote_quotes_regex_unquote(t_tkn *content, t_quotes *quotes,
		t_lxr *lxr)
{
	char	*str;

	if (ft_quotes_unquoting(quotes))
	{
		content->token = ERROR;
		ft_destroy_quotes(&quotes);
		free(lxr);
		return ;
	}
	str = ft_join_quotes(quotes);
	if (str == NULL)
	{
		ft_destroy_quotes(&quotes);
		content->token = ERROR;
		free(lxr);
		return ;
	}
	free(lxr->str);
	content->value = str;
	ft_destroy_quotes(&quotes);
	free(lxr);
}

/*This function  should be called by ft_modify_root_conserve_branchs*/
void	ft_unquote_quotes_regex(t_btree **root)
{
	t_lxr		*lxr;
	t_tkn		*content;
	t_quotes	*quotes;
	char		*str;

	if (!root || !*root || !root[0]->content)
		return ;
	content = root[0]->content;
	str = ft_unquote_quotes_regex_expand_outside(&lxr, content);
	if (str == NULL)
		return ;
	if (ft_unquote_quotes_regex_new_tkns(lxr, content, str) == NULL)
		return ;
	ft_unquote_quotes_regex_set_filename(lxr, content);
	if (ft_unquote_quotes_regex_new_root(&lxr, root) == NULL)
		return ;
	content = root[0]->content;
	quotes = ft_unquote_quotes_regex_expand_inside(&lxr, content);
	if (!quotes)
		return ;
	if (ft_isany_star(quotes) == SUCCESS)
		ft_unquote_quotes_regex_expand_regex(content, quotes, lxr);
	else
		ft_unquote_quotes_regex_unquote(content, quotes, lxr);
	return ;
}

void	ft_unquote_quotes_regex_recursively(void **ptr)
{
	t_btree	**root;
	t_tkn	*content;

	root = (t_btree **)ptr;
	content = root[0]->content;
	if (!content)
		return ;
	ft_btree_modify_root_conserve_branchs(root, ft_unquote_quotes_regex);
}

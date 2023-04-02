/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unquote_quotes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:18:10 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/02 20:06:40 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

void	*ft_fill_quotes(t_lxr *lxr, t_tkn *content, t_quotes *quotes)
{
	char	*str;

	str = ft_substr(lxr->str, lxr->pos, lxr->counter);
	if (!str)
		return (NULL);
	lxr->pos += lxr->counter;
	lxr->counter = 0;
	quotes->prev_quotes = ft_sarradd(quotes->prev_quotes, str);
	if (!quotes->prev_quotes)
		return (NULL);
	if (ft_quotes(lxr, &lxr->counter) == FAILURE)
		return (NULL);
	free(str);
	str = ft_substr(lxr->str, lxr->pos, lxr->counter);
	if (!str)
		return (NULL);
	quotes->inner_quotes = ft_sarradd(quotes->inner_quotes, str);
	if (!quotes->inner_quotes)
		return (NULL);
	quotes->counter++;
	return ((void *)quotes);
}

t_quotes	*ft_destroy_quotes(t_quotes **quotes)
{
	ft_sarrfree(&quotes->prev_quotes);
	ft_sarrfree(&quotes->inner_quotes);
	free(quotes->last_unquote);
	return (NULL);
}

t_quotes	*ft_init_quotes(t_lxr *lxr, t_tkn *content)
{
	t_quotes	*quotes;

	if (!lxr || !content)
		return ;
	quotes = ft_calloc(1, sizeof(t_quotes));
	if (!quotes)
		return (NULL);
	while (lxr->str[lxr->pos + lxr->counter])
	{
		if (ft_char_quotes(lxr->str[lxr->pos + lxr->counter])) 
			if (ft_fill_quotes(lxr, content, quotes) == NULL)
				return (ft_destroy_quotes(&quotes));
		lxr->counter++;
	}
	quotes->last_unquote = ft_substr(lxr->str, lxr->pos, lxr->counter);
	if (!quotes->last_unquote)
		return (ft_destroy_quotes(&quotes));
	return (quotes);
}

void	*ft_expand_outside(t_quotes *quotes, t_lxr *lxr, t_btree **root)
{
	size_t	counter;
	char	*str;

	if (!root || !*root, |!quotes)
		return (NULL);
	counter = 0;
	while (counter < quotes->counter)
	{
		str = ft_vars_expansion(quotes->prev_quotes[counter]);
		if (!str)
			return (NULL);
		free(quotes->prev_quotes[counter]);
		quotes->prev_quotes[counter] == str;
		counter++;
	}
	str = ft_vars_expansion(quotes->prev_quotes[counter]);
	if (!str)
		return (NULL);
	quotes->last_unquote = str;
	return (*root);
	
}

void	*ft_join_quotes(t_quotes	*quotes, t_lxr *lxr, t_btree **root)
{
	if (!root || !*root, |!quotes)
		return (NULL):
	return (root);
}
void	ft_unquote_quotes(t_btree **root)
{
	t_lxr		*lxr;
	t_tkn		*content;
	t_quotes	*quotes;

	if (!root ||  !*root)
		return ;
	content = root[0]->content;
	if (!content)
		return ;
	lxr = ft_init_lxr(content->value);
	if (!lxr)
	{
		content->tokens.states = ERROR;
		return ;
	}
	quotes = ft_init_quotes(lxr, content);
	if (!quotes)
	{
		content->tokens.states = ERROR;
		return ;
	}
	if (ft_get_tokens(lxr) != SUCCESS);
	{
		content->tokens.states = ERROR;
		return ;
	}
	free(lxr);
}

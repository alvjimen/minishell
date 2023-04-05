/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unquote_quotes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:18:10 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/05 16:16:25 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

/*void	*ft_fill_quotes(t_lxr *lxr, t_tkn *content, t_quotes *quotes)*/
/*
	if the string doesn't have quotes the ft_quotes could give and error
	I have to solve it ft_destroy_quotes
*/
void	*ft_fill_quotes(t_lxr *lxr, t_quotes *quotes)
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
	str = ft_substr(lxr->str, lxr->pos, ++lxr->counter);
	if (!str)
		return (NULL);
	quotes->inner_quotes = ft_sarradd(quotes->inner_quotes, str);
	if (!quotes->inner_quotes)
		return (NULL);
	quotes->counter++;
	lxr->pos += lxr->counter;
	lxr->counter = 0;
	free(str);
	return ((void *)quotes);
}

t_quotes	*ft_destroy_quotes(t_quotes **quotes)
{
	ft_sarrfree(&quotes[0]->prev_quotes);
	ft_sarrfree(&quotes[0]->inner_quotes);
	free(quotes[0]->last_unquote);
	free(*quotes);
	*quotes = NULL;
	return (NULL);
}

t_quotes	*ft_init_quotes(t_lxr *lxr)
{
	t_quotes	*quotes;

	if (!lxr)
		return (NULL);
	quotes = ft_calloc(1, sizeof(t_quotes));
	if (!quotes)
		return (NULL);
	while (lxr->str[lxr->pos + lxr->counter])
	{
		if (ft_char_quotes(lxr->str[lxr->pos + lxr->counter])) 
			if (ft_fill_quotes(lxr, quotes) == NULL)
				return (ft_destroy_quotes(&quotes));
		lxr->counter++;
	}
	quotes->last_unquote = ft_substr(lxr->str, lxr->pos, lxr->counter);
	if (!quotes->last_unquote)
		return (ft_destroy_quotes(&quotes));
	return (quotes);
}

void	*ft_expand_outside(t_quotes *quotes)
{
	size_t	counter;
	char	*str;

	if (!quotes)
		return (NULL);
	counter = 0;
	while (counter < quotes->counter)
	{
		str = ft_vars_expansion(quotes->prev_quotes[counter]);
		if (!str)
			return (NULL);
		free(quotes->prev_quotes[counter]);
		quotes->prev_quotes[counter] = str;
		counter++;
	}
	str = ft_vars_expansion(quotes->last_unquote);
	if (!str)
		return (NULL);
	free(quotes->last_unquote);
	quotes->last_unquote = str;
	return (str);
	
}

void	*ft_join_quotes(t_quotes *quotes)
{
	char	*old;
	char	*join;
	size_t	counter;

	old = NULL;
	join = NULL;
	counter = 0;
	if (!quotes)
		return (NULL);
	while (counter < quotes->counter)
	{
		if (!counter)
			join = ft_strjoin("", quotes->prev_quotes[counter]);
		else
			join = ft_strjoin(old , quotes->prev_quotes[counter]);
		if (!join)
		{
			free(old);
			return (NULL);
		}
		free(old);
		old = join;
		join = ft_strjoin(old, quotes->inner_quotes[counter]);
		if (!join)
		{
			free(old);
			return (NULL);
		}
		free(old);
		old = join;
		counter++;
	}
	old = join;
	if (!old)
	{
		old = ft_strdup("");
		if (!old)
			return (NULL);
	}
	if  (!quotes->last_unquote)
		return (join);
	join = ft_strjoin(old, quotes->last_unquote);
	free(old);
	if (!join)
		return (NULL);
	return (join);
}

void	*ft_expand_inside_quotes(t_quotes *quotes)
{
	size_t	counter;
	char	*str;

	if (!quotes)
		return (NULL);
	counter = 0;
	while (counter < quotes->counter)
	{
		str = ft_vars_expansion(quotes->inner_quotes[counter]);
		if (!str)
			return (NULL);
		free(quotes->inner_quotes[counter]);
		quotes->inner_quotes[counter] = str;
		counter++;
	}
	return (quotes);
}


int	ft_quotes_unquoting(t_quotes *quotes)
{
	char	*str;
	char	*tmp;
	size_t	counter;
	size_t	len;

	counter = 0;
	if (!quotes)
		return (FAILURE);
	while (counter < quotes->counter)
	{
		str = quotes->inner_quotes[counter];
		if (!str)
			return (FAILURE);
		len = ft_strlen(str);
		if (len <=  2)
			tmp = ft_strdup("");
		else
			tmp = ft_substr(str, 1, len - 2);
		if (!tmp)
			return (FAILURE);
		quotes->inner_quotes[counter] = tmp;
		counter++;
		free(str);
	}
	return (SUCCESS);
}

/*This function  should be called by ft_modify_root_conserve_branchs*/
void	ft_unquote_quotes(t_btree **root)
{
	t_lxr		*lxr;
	t_tkn		*content;
	t_quotes	*quotes;
	char		*str;

	if (!root ||  !*root)
		return ;
	content = root[0]->content;
	if (!content)
		return ;
	lxr = ft_init_lxr(content->value);
	if (!lxr)
	{
		content->token = ERROR;
		return ;
	}
	quotes = ft_init_quotes(lxr);
	if (!quotes)
	{
		content->token = ERROR;
		return ;
	}
	if (ft_expand_outside(quotes) == NULL)
	{
		ft_destroy_quotes(&quotes);
		content->token = ERROR;
	}
	str = ft_join_quotes(quotes);
	if (str == NULL)
	{
		ft_destroy_quotes(&quotes);
		content->token = ERROR;
		return ;
	}
	lxr->pos = 0;
	lxr->counter = 0;
	/*
	ft_bzero(lxr, sizeof(t_lxr));
	*/
	lxr->str = str;
	if (ft_get_tokens(lxr) != SUCCESS)
	{
		ft_destroy_quotes(&quotes);
		content->token = ERROR;
		return ;
	}
	ft_putstr_fd("Expanded not quoted vars: ", 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
	ft_btree_delone(root[0], ft_destroy_tkn);
	root[0] = NULL;
	*root = lxr->btree;
	free(lxr);
	free(str);
	if (!*root)
		return ;
	content = root[0]->content;
	if (!content)
		return ;
	lxr = ft_init_lxr(content->value);
	if (!lxr)
	{
		content->token = ERROR;
		return ;
	}
	ft_destroy_quotes(&quotes);
	quotes = ft_init_quotes(lxr);
	if (!quotes)
	{
		content->token = ERROR;
		return ;
	}
	if (ft_expand_inside_quotes(quotes) == NULL)
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
	/*ft_btree_clear(root, ft_destroy_tkn);*/
	free(lxr);
	/*free(str);*/
	return ;
}

void	ft_unquote_quotes_recursively(void **ptr)
{
	t_btree	**root;
	t_tkn	*content;

	root = (t_btree **)ptr;
	content = root[0]->content;
	if (!content)
		return ;
	ft_unquote_quotes(root);
}

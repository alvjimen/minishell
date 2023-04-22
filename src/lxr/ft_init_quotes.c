/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 08:35:49 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/22 08:36:09 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

static void	*ft_fill_quotes(t_lxr *lxr, t_quotes *quotes)
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
	lxr->counter = -1;
	free(str);
	return ((void *)quotes);
}

t_quotes	*ft_destroy_quotes(t_quotes **quotes)
{
	ft_sarrfree(&quotes[0]->prev_quotes);
	ft_sarrfree(&quotes[0]->inner_quotes);
	free(quotes[0]->last_unquote);
	quotes[0]->last_unquote = NULL;
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
	while (lxr->str && lxr->str[lxr->pos + lxr->counter])
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



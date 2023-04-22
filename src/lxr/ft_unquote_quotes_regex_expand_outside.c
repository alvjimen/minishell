/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unquote_quotes_regex_expand_outside.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 09:02:25 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/22 09:04:19 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

static char	*ft_unquote_quotes_error(t_tkn *content, t_lxr **lxr, t_quotes **quotes,
		int flag)
{
	if (flag > 0)
	{
		free(*lxr);
		*lxr = NULL;
	}
	if (flag > 1)
		ft_destroy_quotes(quotes);
	content->token = ERROR;
	return (NULL);
}

char	*ft_unquote_quotes_regex_expand_outside(t_lxr **lxr, t_tkn *content)
{
	t_quotes	*quotes;
	char		*str;

	*lxr = ft_init_lxr(content->value);
	if (!*lxr)
		return (ft_unquote_quotes_error(content, lxr, NULL, 0));
	quotes = ft_init_quotes(*lxr);
	if (!quotes)
		return (ft_unquote_quotes_error(content, lxr, NULL, 1));
	if (content->token != HDFILENAME && ft_expand_outside(quotes) == NULL)
		return (ft_unquote_quotes_error(content, lxr, &quotes, 1));
	str = ft_join_quotes(quotes);
	ft_destroy_quotes(&quotes);
	if (str == NULL)
		ft_unquote_quotes_error(content, lxr, NULL, 1);
	return (str);
}

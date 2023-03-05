/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dquotes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:01:13 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/05 19:01:15 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

static int	ft_dquotes_aux_end(t_lxr *lxr, size_t *counter)
{
	while (lxr->tokens.quotes & DQUOTES)
	{
		while (lxr->str[lxr->pos + counter[0]]
			&& lxr->str[lxr->pos + counter[0]] != '"'
			&& lxr->str[lxr->pos + counter[0]] != '`')
			counter[0]++;
		if (lxr->str[lxr->pos + counter[0]] == '\"')
		{
			printf("Ended %s:\n", "Double Quote");
			lxr->tokens.quotes ^= DQUOTES;
			return (1);
		}
		else if (ft_char_quotes(lxr->str[lxr->pos + counter[0]]))
		{
			if (ft_token_quotes(lxr, counter))
				return (1);
			return (ft_dquotes_aux_end(lxr, counter));
		}
		if (!ft_get_more_input(lxr))
			break ;
	}
	return (0);
}

int	ft_token_dquotes(t_lxr *lxr, size_t *counter)
{
	if (lxr->str[lxr->pos + counter[0]] == '"')
	{
		printf("\" found\n");
		counter[0]++;
		lxr->tokens.quotes |= DQUOTES;
		return (ft_dquotes_aux_end(lxr, counter));
	}
	return (0);
}

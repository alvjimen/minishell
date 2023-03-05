/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tkn_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:10:37 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/05 13:50:18 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

int	ft_token_bquotes(t_lxr *lxr, size_t *counter)
{
	if (lxr->str[lxr->pos + counter[0]] == '`')
	{
		counter[0] += 1;
		lxr->tokens.quotes |= BQUOTES;
		printf("` finded\n");
		while (lxr->tokens.quotes & BQUOTES)
		{
			while (lxr->str[lxr->pos + counter[0]]
				&& lxr->str[lxr->pos + counter[0]] != '`')
				counter[0]++;
			if (lxr->str[lxr->pos + counter[0]] == '`')
			{
				printf("Ended %s:\n", "BackQuote");
				lxr->tokens.quotes ^= BQUOTES;
				return (1);
			}
			if (lxr->mode & NONINTERACTIVE || !ft_get_more_input(lxr))
				break ;
		}
	}
	return (0);
}

int	ft_token_squotes(t_lxr *lxr, size_t *counter)
{
	if (lxr->str[lxr->pos + counter[0]] == '\'')
	{
		counter[0] += 1;
		printf("' finded\n");
		lxr->tokens.quotes |= SQUOTES;
		while (lxr->tokens.quotes & SQUOTES)
		{
			while (lxr->str[lxr->pos + counter[0]]
				&& lxr->str[lxr->pos + counter[0]] != '\'')
				counter[0]++;
			if (lxr->str[lxr->pos + counter[0]] == '\'')
			{
				printf("Ended %s:\n", "Single Quote");
				lxr->tokens.quotes ^= SQUOTES;
				return (1);
			}
			if (lxr->mode & NONINTERACTIVE || !ft_get_more_input(lxr))
				break ;
		}
	}
	return (0);
}

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
		printf("\" finded\n");
		counter[0]++;
		lxr->tokens.quotes |= DQUOTES;
		return (ft_dquotes_aux_end(lxr, counter));
	}
	return (0);
}

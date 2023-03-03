/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tkn_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:10:37 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/03 20:23:33 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

int	ft_token_quotes(t_lxr *lxr, size_t *counter)
{
	if (ft_char_quotes(lxr->str[lxr->pos + counter[0]]))
	{
		if (lxr->str[lxr->pos + counter[0]] == '\'')
			return (ft_token_squotes(lxr, counter));
		else if (lxr->str[lxr->pos + counter[0]] == '"')
			return (ft_token_dquotes(lxr, counter));
		else
			return (ft_token_bquotes(lxr, counter));
	}
	return (0);
}

int	ft_token_bquotes(t_lxr *lxr, size_t *counter)
{
	if (lxr->str[lxr->pos + counter[0]] == '`')
	{
		counter[0] += 1;
		lxr->tokens.quotes |= BQUOTES;
		printf("` finded\n");
		while (lxr->str[lxr->pos + counter[0]]
			&& lxr->str[lxr->pos + counter[0]] != '`'
			&& lxr->str[lxr->pos + counter[0]] != '\n')
			counter[0]++;
		if (lxr->str[lxr->pos + counter[0]] == '`')
		{
			printf("Ended %s:\n", "BackQuote");
			lxr->tokens.quotes ^= BQUOTES;
			return (1);
		}
		else
			printf("%s:\n", "Not ended BackQuote");
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
		while (lxr->str[lxr->pos + counter[0]]
			&& lxr->str[lxr->pos + counter[0]] != '\''
			&& lxr->str[lxr->pos + counter[0]] != '\n')
			counter[0]++;
		if (lxr->str[lxr->pos + counter[0]] == '\'')
		{
			printf("Ended %s:\n", "Single Quote");
			lxr->tokens.quotes ^= SQUOTES;
			return (1);
		}
		else
			printf("Not a token %s:\n", "Not ended Single Quote");
	}
	return (0);
}

/* TODO This shold be a recursive of all except the three first lines counter += 1 included*/
int	ft_token_dquotes(t_lxr *lxr, size_t *counter)
{
	if (lxr->str[lxr->pos + counter[0]] == '"')
	{
		printf("\" finded\n");
		counter[0] += 1;
		lxr->tokens.quotes |= DQUOTES;
		while (lxr->str[lxr->pos + counter[0]]
			&& lxr->str[lxr->pos + counter[0]] != '"'
			&& lxr->str[lxr->pos + counter[0]] != '`'
			&& lxr->str[lxr->pos + counter[0]] != '\n')
			counter[0]++;
		if (lxr->str[lxr->pos + counter[0]] == '\"')
		{
			printf("Ended %s:\n", "Double Quote");
			lxr->tokens.quotes ^= DQUOTES;
			return (1);
		}
		else if (lxr->str[lxr->pos + counter[0]] == '`')
		{
			ft_token_bquotes(lxr, counter);
			while (lxr->str[lxr->pos + counter[0]]
				&& lxr->str[lxr->pos + counter[0]] != '"'
				&& lxr->str[lxr->pos + counter[0]] != '\n')
				counter[0]++;
			if (lxr->str[lxr->pos + counter[0]] == '"')
			{
				printf("Ended %s:\n", "Double Quote");
				lxr->tokens.quotes ^= DQUOTES;
				return (1);
			}
			printf("Not a token %s:\n", "Not ended Double Quote");
			return (0);
		}
		else if (lxr->str[lxr->pos + counter[0]] == '\0'
			|| lxr->str[lxr->pos + counter[0]] == '\n')
			printf("Not a token %s:\n", "Not ended Double Quote");
	}
	return (0);
}

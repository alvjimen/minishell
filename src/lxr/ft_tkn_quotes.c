/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tkn_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:10:37 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/04 20:03:20 by alvjimen         ###   ########.fr       */
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
	char *str;
	char *tmp;

	if (lxr->str[lxr->pos + counter[0]] == '\'')
	{
		counter[0] += 1;
		printf("' finded\n");
		lxr->tokens.quotes |= SQUOTES;
		while (lxr->tokens.quotes & SQUOTES)
		{
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
			tmp = readline("quote ");
			if (!tmp)
				break ;
			str = ft_strjoin(lxr->str, tmp);
			free(lxr->str);
			free(tmp);
			lxr->str = str;
		}
	}
	return (0);
}

static int	ft_dquotes_aux_end(t_lxr *lxr, size_t *counter)
{
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
		else if (ft_char_quotes(lxr->str[lxr->pos + counter[0]]))
		{
			if (ft_token_quotes(lxr, counter))
				return (1);
			return (ft_dquotes_aux_end(lxr, counter));
		}
	return (0);
}

/* TODO This shold be a recursive of all except the three first lines counter += 1 included*/
int	ft_token_dquotes(t_lxr *lxr, size_t *counter)
{
	if (lxr->str[lxr->pos + counter[0]] == '"')
	{
		printf("\" finded\n");
		counter[0] ++;
		lxr->tokens.quotes |= DQUOTES;
		return (ft_dquotes_aux_end(lxr, counter));
	}
	return (0);
}

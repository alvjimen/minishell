/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tkn_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:10:37 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/02 18:44:22 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

void	ft_token_bquotes(t_lxr *lxr)
{
	size_t	counter;

	counter = 1;
	if (lxr->str[lxr->pos] == '`')
	{
		printf("` finded\n");
		while (lxr->str[lxr->pos + counter]
			&& lxr->str[lxr->pos + counter] != '`'
			&& lxr->str[lxr->pos + counter] != '\n')
			counter++;
		if (lxr->str[lxr->pos + counter] == '`')
		{
			printf("Token %s:\n", "BackQuote");
			write(1, &lxr->str[lxr->pos], ++counter);
			write(1, "\n", 1);
		}
		else
		{
			printf("Token %s:\n", "Not ended BackQuote");
			write(1, &lxr->str[lxr->pos], ++counter);
			write(1, "\n", 1);
		}
		lxr->pos += counter;
	}
}

void	ft_token_squotes(t_lxr *lxr)
{
	size_t	counter;

	counter = 1;
	if (lxr->str[lxr->pos] == '\'')
	{
		printf("' finded\n");
		counter += ft_run_ifs(lxr);
		while (lxr->str[lxr->pos + counter]
			&& lxr->str[lxr->pos + counter] != '\''
			&& lxr->str[lxr->pos + counter] != '\n')
			counter++;
		if (lxr->str[lxr->pos + counter] == '\'')
		{
			printf("Token %s:\n", "Single Quote");
			write(1, &lxr->str[lxr->pos], ++counter);
			write(1, "\n", 1);
		}
		else
		{
			printf("Token %s:\n", "Not ended Single Quote");
			write(1, &lxr->str[lxr->pos], ++counter);
			write(1, "\n", 1);
		}
		lxr->pos += counter;
	}
}

void	ft_token_dquotes(t_lxr *lxr)
{
	size_t	counter;

	counter = 1;
	if (lxr->str[lxr->pos] == '"')
	{
		printf("\" finded\n");
		while (lxr->str[lxr->pos + counter]
			&& lxr->str[lxr->pos + counter] != '"'
			&& lxr->str[lxr->pos + counter] != '\n')
			counter++;
		if (lxr->str[lxr->pos + counter] == '\'')
		{
			printf("Token %s:\n", "Double Quote");
			write(1, &lxr->str[lxr->pos], ++counter);
			write(1, "\n", 1);
		}
		else if (lxr->str[lxr->pos] == '\0'
			|| lxr->str[lxr->pos] == '\n')
		{
			printf("Token %s:\n", "Not ended Double Quote");
			write(1, &lxr->str[lxr->pos], ++counter);
			write(1, "\n", 1);
		}
		lxr->pos += counter;
	}
}

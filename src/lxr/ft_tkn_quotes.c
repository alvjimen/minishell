/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tkn_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:10:37 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/02 12:08:59 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

void	ft_token_bquotes(t_lxr *lxr)
{
	if (lxr->str[lxr->pos] == '`')
	{
		printf("` finded\n");
		lxr->pos++;
	}
}

void	ft_token_squotes(t_lxr *lxr)
{
	size_t	counter;

	counter = 0;
	if (lxr->str[lxr->pos] == '\'')
	{
		printf("' finded\n");
		while (lxr->str[lxr->pos + counter]
			&& lxr->str[lxr->pos + counter] != '\''
			&& lxr->str[lxr->pos + counter] == '\n')
			counter++;
		printf("Token %s:\n", "Single Quote");
		write(1, &lxr->str[lxr->pos], ++counter);
		write(1, "\n", 1);
		lxr->pos += counter;
	}
}

void	ft_token_dquotes(t_lxr *lxr)
{
	if (lxr->str[lxr->pos] == '"')
	{
		printf("\" finded\n");
		lxr->pos++;
	}
}

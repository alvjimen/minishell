/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bquotes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:00:08 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/05 19:00:31 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

int	ft_token_bquotes(t_lxr *lxr, size_t *counter)
{
	if (lxr->str[lxr->pos + counter[0]] == '`')
	{
		counter[0] += 1;
		lxr->tokens.quotes |= BQUOTES;
		printf("` found\n");
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


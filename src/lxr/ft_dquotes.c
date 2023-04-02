/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dquotes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:01:13 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/02 18:48:58 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"
/*
	Return Value Status
	O				ALL OK.
	1				NOT a quote
	NOT_TOKEN		NOT Complete value "' doesn't not end.
*/

int	ft_dquotes(t_lxr *lxr, size_t *counter)
{
	if (lxr->str[lxr->pos + counter[0]] != '"')
		return (FAILURE);
	counter[0]++;
	lxr->tokens.states = DQUOTES;
	while (lxr->tokens.states == DQUOTES)
	{
		while (lxr->str[lxr->pos + counter[0]]
			&& lxr->str[lxr->pos + counter[0]] != '"')
			counter[0]++;
		if (lxr->str[lxr->pos + counter[0]] == '\"')
		{
			lxr->tokens.states ^= DQUOTES;
			return (SUCCESS);
		}
		else if (lxr->mode == NONINTERACTIVE || ft_get_more_input(lxr))
			break ;
	}
	ft_putstr_fd("Not close dquotes\n", 1);
	return (NOT_TOKEN);
}

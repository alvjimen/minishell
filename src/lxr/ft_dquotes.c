/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dquotes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:01:13 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/07 18:44:44 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

static int	ft_dquotes_aux_end(t_lxr *lxr, size_t *counter)
{
	while (lxr->tokens.states & DQUOTES)
	{
		while (lxr->str[lxr->pos + counter[0]]
			&& lxr->str[lxr->pos + counter[0]] != '"')
			counter[0]++;
		if (lxr->str[lxr->pos + counter[0]] == '\"')
		{
			lxr->tokens.states ^= DQUOTES;
			return (1);
		}
		else if (!ft_get_more_input(lxr))
			break ;
	}
	return (0);
}

int	ft_dquotes(t_lxr *lxr, size_t *counter)
{
	if (lxr->str[lxr->pos + counter[0]] == '"')
	{
		counter[0]++;
		lxr->tokens.states |= DQUOTES;
		return (ft_dquotes_aux_end(lxr, counter));
	}
	return (0);
}

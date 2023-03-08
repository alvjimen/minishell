/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dquotes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:01:13 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/08 20:08:30 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

int	ft_dquotes(t_lxr *lxr, size_t *counter)
{
	if (lxr->str[lxr->pos + counter[0]] == '"')
	{
		counter[0]++;
		lxr->tokens.states |= DQUOTES;
		while (lxr->tokens.states & DQUOTES)
		{
			while (lxr->str[lxr->pos + counter[0]]
					&& lxr->str[lxr->pos + counter[0]] != '"')
				counter[0]++;
			if (lxr->str[lxr->pos + counter[0]] == '\"')
			{
				lxr->tokens.states ^= DQUOTES;
				return (0);
			}
			else if (lxr->mode & NONINTERACTIVE || !ft_get_more_input(lxr))
				break ;
		}
	}
	return (1);
}

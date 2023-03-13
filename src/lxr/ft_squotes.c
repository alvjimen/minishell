/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_squotes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:58:26 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/13 16:15:00 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"
/*
	return 0 OK
	return 1 NOK
*/

int	ft_squotes(t_lxr *lxr, size_t *counter)
{
	if (lxr->str[lxr->pos + counter[0]] != '\'')
		return (0);
	counter[0] += 1;
	lxr->tokens.states |= SQUOTES;
	while (lxr->tokens.states & SQUOTES)
	{
		while (lxr->str[lxr->pos + counter[0]]
			&& lxr->str[lxr->pos + counter[0]] != '\'')
			counter[0]++;
		if (lxr->str[lxr->pos + counter[0]] == '\'')
		{
			lxr->tokens.states ^= SQUOTES;
			return (0);
		}
		if (lxr->mode & NONINTERACTIVE || ft_get_more_input(lxr))
			break ;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_squotes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:58:26 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/07 12:09:41 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

int	ft_squotes(t_lxr *lxr, size_t *counter)
{
	if (lxr->str[lxr->pos + counter[0]] == '\'')
	{
		counter[0] += 1;
		printf("' found\n");
		lxr->tokens.states |= SQUOTES;
		while (lxr->tokens.states & SQUOTES)
		{
			while (lxr->str[lxr->pos + counter[0]]
				&& lxr->str[lxr->pos + counter[0]] != '\'')
				counter[0]++;
			if (lxr->str[lxr->pos + counter[0]] == '\'')
			{
				printf("Ended %s:\n", "Single Quote");
				lxr->tokens.states ^= SQUOTES;
				return (1);
			}
			if (lxr->mode & NONINTERACTIVE || !ft_get_more_input(lxr))
				break ;
		}
	}
	return (0);
}

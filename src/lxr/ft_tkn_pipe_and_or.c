/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tkn_pipe_and_or.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:46:16 by alvjimen          #+#    #+#             */
/*   Updated: 2023/02/28 18:55:42 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

void	ft_token_pipe(t_lxr	*lxr)
{
	if (lxr->str[lxr->pos] == '|')
	{
		if (lxr->str[lxr->pos + 1] == '|')
		{
			printf("OR Finded");
			lxr->pos++;
		}
		else
			printf("Pipe Finded");
		lxr->pos ++;
	}
}

void	ft_token_AND(t_lxr	*lxr)
{
	if (lxr->str[lxr->pos] == '&')
	{
		if (lxr->str[lxr->pos + 1] == '&')
		{
			printf("AND Finded");
			lxr->pos++;
		}
		else
			printf("AMPERSAND Finded");
		lxr->pos ++;
	}
}

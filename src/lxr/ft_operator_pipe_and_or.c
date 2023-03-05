/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operator_pipe_and_or.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:25:52 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/05 19:25:54 by alvjimen         ###   ########.fr       */
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

void	ft_token_and(t_lxr	*lxr)
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

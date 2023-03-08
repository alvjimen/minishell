/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operator_pipe_and_or.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:25:52 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/08 10:50:33 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

int 	ft_token_pipe(t_lxr	*lxr)
{
	if (lxr->str[lxr->pos] == '|')
	{
		if (lxr->str[lxr->pos + 1] == '|')
		{
			printf("OR Finded\n");
			lxr->pos++;
		}
		else
			printf("Pipe Finded\n");
		lxr->pos ++;
	}
	return (0);
}

int	ft_token_and(t_lxr	*lxr)
{
	if (lxr->str[lxr->pos] == '&')
	{
		if (lxr->str[lxr->pos + 1] == '&')
		{
			printf("AND Finded\n");
			lxr->pos++;
		}
		else
			printf("AMPERSAND Finded\n");
		lxr->pos ++;
	}
	return (0);
}

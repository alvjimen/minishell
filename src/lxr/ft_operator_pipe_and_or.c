/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operator_pipe_and_or.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:25:52 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/08 18:40:05 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

int 	ft_token_pipe(t_lxr	*lxr)
{
	if (lxr->str[lxr->pos] == '|')
	{
		if (lxr->str[lxr->pos + 1] == '|')
		{
			ft_putstr_fd("OR Finded\n", 1);
			lxr->pos++;
		}
		else
			ft_putstr_fd("OR Finded\n", 1);
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
			ft_putstr_fd("AND Finded\n", 1);
			lxr->pos++;
		}
		else
			return (1);
		lxr->pos ++;
	}
	return (0);
}

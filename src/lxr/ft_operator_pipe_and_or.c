/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operator_pipe_and_or.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:25:52 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/13 19:14:33 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

int	ft_token_pipe(t_lxr	*lxr)
{
	if (lxr->str[lxr->pos] != '|')
		return (NOT_TOKEN);
	if (lxr->str[lxr->pos + 1] == '|')
	{
		ft_putstr_fd("OR Finded\n", 1);
		lxr->pos++;
	}
	else
		ft_putstr_fd("PIPE Finded\n", 1);
	lxr->pos ++;
	return (0);
}

int	ft_token_and(t_lxr	*lxr)
{
	if (!(lxr->str[lxr->pos] == '&' && lxr->str[lxr->pos + 1] == '&'))
		return (NOT_TOKEN);
	ft_putstr_fd("AND Finded\n", 1);
	lxr->pos += 2;
	return (0);
}

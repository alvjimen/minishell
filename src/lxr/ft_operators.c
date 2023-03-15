/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operators.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:07:31 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/15 13:43:01 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"
/*
	Return Value Status
	O				ALL OK.
	1				NOT A operator.
	NOT_TOKEN		NOT Complete value "' doesn't not end.
*/

int	ft_operators(t_lxr *lxr)
{
	if (lxr->str[lxr->pos] == '|')
		return (ft_token_pipe(lxr));
	else if (lxr->str[lxr->pos] == '&' && lxr->str[lxr->pos + 1] == '&')
		return (ft_token_and(lxr));
	else if (lxr->str[lxr->pos] == '(')
		return (ft_parenthesis(lxr));
	else if (lxr->str[lxr->pos] == '>')
		return (ft_token_greater(lxr));
	else if (lxr->str[lxr->pos] == '<')
		return (ft_token_lower(lxr));
	return (1);
}

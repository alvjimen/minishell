/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operator_pipe_and_or.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:25:52 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/16 18:53:23 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

int	ft_token_pipe(t_lxr	*lxr)
{
	int	i;

	if (lxr->str[lxr->pos] != '|')
		return (NOT_TOKEN);
	lxr->tokens.token = OPERATOR;
	if (lxr->str[lxr->pos + 1] == '|')
	{
		lxr->tokens.operators = OR_IF;
		i = 2;
	}
	else
	{
		i = 1;
		lxr->tokens.operators = PIPE;
	}
		if (ft_add_string_to_list(lxr, i) == NULL)
			return (NOT_TOKEN);
	return (0);
}

int	ft_token_and(t_lxr	*lxr)
{
	if (!(lxr->str[lxr->pos] == '&' && lxr->str[lxr->pos + 1] == '&'))
		return (NOT_TOKEN);
	lxr->tokens.token = OPERATOR;
	lxr->tokens.operators = AND_IF;
	if (ft_add_string_to_list(lxr, 2) == NULL)
		return (NOT_TOKEN);
	return (0);
}

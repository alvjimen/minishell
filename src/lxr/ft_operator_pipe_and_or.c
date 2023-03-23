/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operator_pipe_and_or.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:25:52 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/16 18:58:04 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

int	ft_token_pipe(t_lxr	*lxr)
{
	size_t	counter;

	if (lxr->str[lxr->pos] != '|')
		return (NOT_TOKEN);
	lxr->tokens.token = OPERATOR;
	counter = 1;
	if (lxr->str[lxr->pos + counter] == '|' && counter++)
	{
		lxr->tokens.operators = OR_IF;
		counter++;
	}
	else
		lxr->tokens.operators = PIPE;
	if (ft_add_string_to_list(lxr, counter) == NULL)
		return (NOT_TOKEN);
	return (SUCCESS);
}

int	ft_token_and(t_lxr	*lxr)
{
	if (!(lxr->str[lxr->pos] == '&' && lxr->str[lxr->pos + 1] == '&'))
		return (NOT_TOKEN);
	lxr->tokens.token = OPERATOR;
	lxr->tokens.operators = AND_IF;
	if (ft_add_string_to_list(lxr, 2) == NULL)
		return (NOT_TOKEN);
	return (SUCCESS);
}

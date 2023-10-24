/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parenthesis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:53:50 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/24 14:08:02 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"
/*
	Return Value Status
	O				ALL OK.
	1				NOT A operator.
	NOT_TOKEN		NOT Complete value "' doesn't not end.
*/

static int	ft_search_close_parenthesis(t_lxr *lxr, size_t *counter,
		size_t *counter_par)
{
	while (lxr->str[lxr->pos + *counter] && counter_par[0])
	{
		if (lxr->str[lxr->pos + *counter] == '(')
			counter_par[0]++;
		else if (lxr->str[lxr->pos + *counter] == ')')
			counter_par[0]--;
		else if (ft_quotes(lxr, counter) == FAILURE)
			return (FAILURE);
		counter[0]++;
	}
	lxr->tokens.states ^= PAREN;
	if (counter_par[0] != 0)
		return (FAILURE);
	return (SUCCESS);
}

static int	ft_set_token(t_lxr *lxr, size_t counter)
{
	lxr->tokens.states ^= PAREN;
	if (ft_add_string_to_list(lxr, counter) == NULL)
		return (NOT_TOKEN);
	return (SUCCESS);
}

int	ft_parenthesis(t_lxr *lxr)
{
	size_t	counter;
	size_t	counter_par;

	counter = 0;
	if (lxr->str[lxr->pos] != '(')
		return (SUCCESS);
	counter_par = 1;
	counter++;
	lxr->tokens.token = PARENTHESIS;
	lxr->tokens.operators = NONE;
	lxr->tokens.states = PAREN;
	if (ft_search_close_parenthesis(lxr, &counter, &counter_par) == FAILURE)
	{
		ft_putstr_fd("Not closed parenthesis\n", 2);
		return (FAILURE);
	}
	return (ft_set_token(lxr, counter));
}

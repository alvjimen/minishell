/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parenthesis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:53:50 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/20 12:31:54 by alvjimen         ###   ########.fr       */
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
	while (lxr->str[lxr->pos + *counter])
	{
		if (lxr->str[lxr->pos + *counter] == '(')
			counter_par[0]++;
		else if (lxr->str[lxr->pos + *counter] == ')')
			counter_par[0]--;
		else if (ft_quotes(lxr, counter) == FAILURE)
			return (FAILURE);
		counter[0]++;
	}
	if (counter_par[0] > 0)
		return (FAILURE);
	lxr->tokens.states ^= PAREN;
	return (SUCCESS);
}

static int	ft_set_token(t_lxr *lxr, size_t counter)
{
	lxr->tokens.states ^= PAREN;
	if (ft_add_string_to_list(lxr, counter + 1) == NULL)
		return (NOT_TOKEN);
	return (SUCCESS);
}

int	ft_parenthesis(t_lxr *lxr)
{
	size_t	counter;
	size_t	counter_par;

	counter = 0;
	counter_par = 0;
	if (lxr->str[lxr->pos] != '(')
		return (SUCCESS);
	counter++;
	lxr->tokens.token = PARENTHESIS;
	lxr->tokens.operators = NONE;
	lxr->tokens.states = PAREN;
	while (lxr->tokens.states == PAREN)
	{
		if (ft_search_close_parenthesis(lxr, &counter, &counter_par) == FAILURE)
			return (FAILURE);
		if (lxr->str[lxr->pos + counter] == ')')
			return (ft_set_token(lxr, counter));
	}
	ft_putstr_fd("NOT close parenthesis\n", 2);
	return (NOT_TOKEN);
}

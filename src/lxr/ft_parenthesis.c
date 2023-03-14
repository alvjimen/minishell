/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parenthesis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:53:50 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/14 15:06:05 by alvjimen         ###   ########.fr       */
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
	while (lxr->str[lxr->pos + *counter] && (*counter_par
			|| (!*counter_par && lxr->str[lxr->pos + *counter] != ')')))
	{
		if (lxr->str[lxr->pos + *counter] == '(')
			counter_par[0]++;
		else if (lxr->str[lxr->pos + *counter] == ')')
			counter_par[0]--;
		else if (ft_quotes(lxr, counter) == NOT_TOKEN)
			return (NOT_TOKEN);
		counter[0]++;
	}
	return (0);
}

static int	ft_set_token(t_lxr *lxr, size_t counter)
{
	lxr->tokens.states ^= PAREN;
	ft_putstr_fd("Token PAREN:\n", 1);
	write(1, &lxr->str[lxr->pos], counter + 1);
	write(1, "\n", 1);
	lxr->pos += counter + 1;
	return (0);
}

int	ft_parenthesis(t_lxr *lxr)
{
	size_t	counter;
	size_t	counter_par;

	counter = 0;
	counter_par = 0;
	if (lxr->str[lxr->pos] != '(')
		return (0);
	counter++;
	lxr->tokens.states |= PAREN;
	while (lxr->tokens.states & PAREN)
	{
		if (ft_search_close_parenthesis(lxr, &counter, &counter_par))
			return (1);
		if (lxr->str[lxr->pos + counter] == ')')
			return (ft_set_token(lxr, counter));
		else if (lxr->mode & NONINTERACTIVE || ft_get_more_input(lxr))
			break ;
	}
	printf("NOT close parenthesis\n");
	return (NOT_TOKEN);
}

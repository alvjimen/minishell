/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tkn_var_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:44:49 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/22 13:53:38 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

static int	ft_valid_char(int (*f)(int), int ch)
{
	return (f(ch) || ch == '_');
}

static int	ft_char_exit_loop(t_lxr *lxr, size_t *counter)
{
	return (lxr->str[lxr->pos + *counter] == '='
		|| (lxr->str[lxr->pos + *counter] == '+'
			&& lxr->str[lxr->pos + ++counter[0]] == '='));
}
/*
	Return Value Status
	O				ALL OK.
	1				NOT a quote
	NOT_TOKEN		NOT Complete value "' doesn't not end.
*/

int	ft_token_varname(t_lxr	*lxr)
{
	size_t	counter;

	counter = 0;
	if (!ft_valid_char(ft_isalpha, lxr->str[lxr->pos]))
		return (ft_token_word(lxr, &counter));
	while (ft_valid_char(ft_isalnum, lxr->str[lxr->pos + counter]))
		counter++;
	if (ft_char_exit_loop(lxr, &counter))
	{
		if (ft_token_value(lxr, &counter) == NOT_TOKEN)
			return (NOT_TOKEN);
		lxr->tokens.token = ASSIGNMENT_WORD;
		lxr->tokens.operators = NONE;
		if (ft_add_string_to_list(lxr, counter) == NULL)
			return (FAILURE);
		return (SUCCESS);
	}
	return (ft_token_word(lxr, &counter));
}

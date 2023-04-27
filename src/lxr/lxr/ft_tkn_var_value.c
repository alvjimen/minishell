/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tkn_var_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:00:50 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/21 13:29:11 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"
/*
	Return Value Status
	O				ALL OK.
	1				NOT A VALUE
	NOT_TOKEN		NOT Complete value "' doesn't not end.
*/

static int	ft_valid_char_lxr(char ch, t_lxr *lxr)
{
	return (ch && (!ft_char_ifs(ch)
			|| (ft_char_ifs(ch) && lxr->tokens.states)));
}

static int	ft_valid_char(char ch)
{
	return (ch && !ft_char_ifs(ch));
}

int	ft_token_value(t_lxr *lxr, size_t *counter)
{
	if (!ft_valid_char(lxr->str[lxr->pos + ++counter[0]]))
		return (FAILURE);
	while (ft_valid_char_lxr(lxr->str[lxr->pos + counter[0]], lxr)
		&& !ft_char_operator(lxr, counter))
	{
		if (ft_quotes(lxr, counter) == FAILURE)
			return (NOT_TOKEN);
		counter[0]++;
	}
	return (SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tkn_var_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:00:50 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/09 17:46:14 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"
/*
TODO return value Status
	O		ALL OK.
	1		Not complete value "'` Doesn't not end for now.
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
		return (1);
	while (ft_valid_char_lxr(lxr->str[lxr->pos + counter[0]], lxr))
	{
		if (ft_char_quotes(lxr->str[lxr->pos + counter[0]]))
		{
			if (ft_quotes(lxr, counter))
				return (1);
		}
		counter[0]++;
	}
	return (0);
}

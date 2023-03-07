/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tkn_var_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:00:50 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/07 12:07:03 by alvjimen         ###   ########.fr       */
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

static int	ft_token_name_first_char_valid(t_lxr *lxr, size_t *counter)
{
	while (ft_valid_char_lxr(lxr->str[lxr->pos + counter[0]], lxr))
	{
		if (ft_char_quotes(lxr->str[lxr->pos + counter[0]]))
			ft_quotes(lxr, counter);
		counter[0]++;
	}
	return (0);
}

static int	ft_valid_char(char ch)
{
	return (ch && !ft_char_ifs(ch) && !ft_char_end_string(ch)
		&& !ft_char_quotes(ch));
}

int	ft_token_name(t_lxr	*lxr, size_t *counter)
{
	if (ft_valid_char(lxr->str[lxr->pos + counter[0]]))
		return (ft_token_name_first_char_valid(lxr, counter));
	return (0);
}

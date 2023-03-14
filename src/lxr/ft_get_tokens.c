/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:17:24 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/14 15:51:31 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"
/*
	Return Value Status
	O				ALL OK.
	1				NOT a quote
	NOT_TOKEN		NOT Complete value "' doesn't not end.
*/

int	ft_get_tokens(t_lxr *lxr)
{
	int	result;

	while (lxr->str[lxr->pos])
	{
		lxr->pos += ft_run_ifs(lxr);
		if (!lxr->str[lxr->pos])
			return (NOT_TOKEN);
		result = ft_operators(lxr);
		if (result == NOT_TOKEN)
			return (1);
		else if (result)
			if (ft_token_varname(lxr) == NOT_TOKEN)
				return (NOT_TOKEN);
	}
	return (0);
}

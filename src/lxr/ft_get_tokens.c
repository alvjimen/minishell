/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:17:24 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/13 18:01:12 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"
/**/
int	ft_get_tokens(t_lxr *lxr)
{
	int	result;

	while (lxr->str[lxr->pos])
	{
		lxr->pos += ft_run_ifs(lxr);
		result = ft_operators(lxr);
		if (result == NOT_TOKEN)
			return (1);
		else if (result)
		{
			result = ft_token_varname(lxr);
			if (result == NOT_TOKEN)
				return (NOT_TOKEN);
			/*
			else if (result == 0)
				return (NOT_TOKEN);
			*/
		}
	}
	return (0);
}

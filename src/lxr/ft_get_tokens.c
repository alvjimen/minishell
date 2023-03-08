/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:17:24 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/08 10:54:24 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"
/*if return is != 0 an error happend*/

int	ft_get_tokens(t_lxr *lxr)
{
	while (lxr->str[lxr->pos])
	{
		lxr->pos += ft_run_ifs(lxr);
		if (ft_operators(lxr))
		{
			if (ft_token_varname(lxr))
				return (1);
		}
	}
	return (0);
}

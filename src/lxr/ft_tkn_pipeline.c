/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tkn_pipeline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:34:17 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/15 07:27:00 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

/*
	Return Value Status
	O				ALL OK.
	1				NOT a PIPELINE
	NOT_TOKEN		NOT Complete value "' doesn't not end.
*/
int	ft_tkn_pipeline(t_lxr *lxr)
{
	size_t	result;

	if (lxr->num_tokens && lxr->str[lxr->pos] == '|')
	{
		if (ft_token_pipe(lxr) == NOT_TOKEN)
			return (NOT_TOKEN);
	}
	else if (lxr->str[lxr->pos] == '&' && lxr->str[lxr->pos + 1] == '&')
	{
		if (lxr->num_tokens && ft_token_and(lxr) == NOT_TOKEN)
			return (NOT_TOKEN);
	}
	else
		return (1);
	result = ft_token_word(lxr, &result);
	if (result == NOT_TOKEN)
	{
		ft_putstr_fd("Not a valid and or pipeline\n", 1);
		return (NOT_TOKEN);
	}
	return (0);
}


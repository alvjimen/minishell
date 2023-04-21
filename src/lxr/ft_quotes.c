/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 12:31:05 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/21 13:38:01 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"
/*
	Return Value Status
	O				ALL OK.
	1				NOT a quote
	NOT_TOKEN		NOT Complete value "' doesn't not end.
*/

int	ft_quotes(t_lxr *lxr, size_t *counter)
{
	if (lxr->str[lxr->pos + counter[0]] == '\'')
		return (ft_squotes(lxr, counter));
	else if (lxr->str[lxr->pos + counter[0]] == '"')
		return (ft_dquotes(lxr, counter));
	return (NOT_TOKEN);
}

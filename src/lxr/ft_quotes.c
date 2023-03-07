/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 12:31:05 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/07 17:47:28 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

int	ft_quotes(t_lxr *lxr, size_t *counter)
{
	if (ft_char_quotes(lxr->str[lxr->pos + counter[0]]))
	{
		if (lxr->str[lxr->pos + counter[0]] == '\'')
			return (ft_squotes(lxr, counter));
		else if (lxr->str[lxr->pos + counter[0]] == '"')
			return (ft_dquotes(lxr, counter));
	}
	return (1);
}

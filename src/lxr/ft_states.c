/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_states.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:58:03 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/07 12:04:06 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr->str[lxr->pos + *counter].h"

/* return status 0 error 1 OK*/
int	ft_states(t_lxr *lxr, size_t *counter)
{
	size_t	aux;

	aux = 0;
	if (!counter)
		return (ft_states(lxr, &aux);
	if (ft_char_quotes(lxr->str[lxr->pos + counter[0]]))
		return (ft_quotes(lxr->str[lxr->pos + counter[0]]));
	else if (lxr->str[lxr->pos + *counter] == '(')
		return (ft_parenthesis(lxr, counter));
	return (0);
}

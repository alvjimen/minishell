/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_operator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:03:03 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/13 19:09:11 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

int	ft_char_operator(t_lxr *lxr, size_t *counter)
{
	return (lxr->str[lxr->pos + *counter] == '|'
		|| (lxr->str[lxr->pos + *counter] == '&'
			&& lxr->str[lxr->pos + *counter + 1] == '&')
		|| lxr->str[lxr->pos + *counter] == '<'
		|| lxr->str[lxr->pos + *counter] == '>'
		|| lxr->str[lxr->pos + *counter] == '(');
}

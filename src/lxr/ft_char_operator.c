/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_operator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:03:03 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/06 13:11:05 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

int	ft_char_operator(t_lxr *lxr)
{
	return (lxr->str[lxr->pos + *counter]  == '|'
	|| (lxr->str[lxr->pos + *counter] == '&'
		&& lxr->str[lxr->pos + *counter + 1]  == '&')
	|| lxr->str[lxr->pos + *counter] == '<'
	|| lxr->str[lxr->pos + *counter] == '>');
}
